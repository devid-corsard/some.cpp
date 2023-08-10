#include "util.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

// 1. Whe are checking if count of open brackets equals to count of closing br.;
//
// 2. Check if closing has a corresponding open on right place;

using std::get;
using std::holds_alternative;

using namespace std;

enum class ErrorReason {
    REDUNANT_CLOSE,
    UNCLOSED,
    INCORRECT_CLOSE,
};

unique_ptr<map<ErrorReason, string>> POSSIBLE_ERRORS = nullptr;

using Success = bool;
using ErrorPosition = unsigned;
using ErrorString = const string*;
using ErrorChar_or_nullptr = optional<const char*>; // can be NULLPTR
using GuardError =
    tuple<ErrorReason, ErrorString, ErrorChar_or_nullptr, ErrorPosition>;
using GuardErrors = vector<GuardError>;
using GuardResult = variant<Success, GuardErrors>;

class OpenCloseGuard {

  public:
    OpenCloseGuard() {}

    GuardResult check(const string* s) {
        check_redunant_closing(s);
        check_unclosed();
        check_incorrect_closing(s);
        if (errors.size()) {
            return errors;
        }
        return true;
    }

  private:
    unsigned int squirly;
    unsigned int bracket;
    unsigned int paren;
    unsigned int ok_pairs;
    unsigned int cur_shift;
    GuardErrors errors;
    GuardResult result;

    bool is_opening(const char* c) {
        if (*c == '{' || *c == '[' || *c == '(') {
            return true;
        }
        return false;
    }
    inline unsigned int shift_on(unsigned int* n) { return *n * 2; }

    void create_error(ErrorReason reson, const string* s,
                      string::const_iterator iter) {
        ErrorString e_str = s;
        ErrorChar_or_nullptr e_char = &*iter;
        ErrorPosition e_pos = iter - s->begin();

        GuardError err = make_tuple(reson, e_str, e_char, e_pos);
        errors.push_back(err);
    }

    void check_redunant_closing(const string* s) {
        for (string::const_iterator iter = s->begin(); iter != s->end();
             ++iter) {
            switch (*iter) {
            case '{':
                squirly++;
                break;
            case '[':
                bracket++;
                break;
            case '(':
                paren++;
                break;
            case ')':
                if (paren == 0) {
                    create_error(ErrorReason::REDUNANT_CLOSE, s, iter);
                } else {
                    paren--;
                }
                break;
            case ']':
                if (bracket == 0) {
                    create_error(ErrorReason::REDUNANT_CLOSE, s, iter);
                } else {
                    bracket--;
                }
                break;
            case '}':
                if (squirly == 0) {
                    create_error(ErrorReason::REDUNANT_CLOSE, s, iter);
                } else {
                    squirly--;
                }
                break;
            }
        }
    }

    void check_unclosed() {
        if (squirly + bracket + paren != 0) {
            GuardError err =
                make_tuple(ErrorReason::UNCLOSED, nullptr, nullopt, 0);
            errors.push_back(err);
        }
    }

    void check_incorrect_closing(const string* s) {
        for (string::const_iterator iter = s->begin(); iter != s->end();
             ++iter) {
            if (is_opening(&*iter)) {
                cur_shift = 0;
                continue;
            }
            int cur_char_code = *iter;
            int posible_match = *iter == 41 ? *(iter - 1 - cur_shift) + 1
                                            : *(iter - 1 - cur_shift) + 2;

            if (posible_match != cur_char_code) {
                create_error(ErrorReason::INCORRECT_CLOSE, s, iter);
                break;
            }

            ok_pairs++;
            cur_shift = shift_on(&ok_pairs);
        }
    }
};

int main() {
    POSSIBLE_ERRORS = std::make_unique<std::map<ErrorReason, std::string>>(
        std::map<ErrorReason, std::string>{
            {ErrorReason::UNCLOSED,        "There is uclosed symbol."         },
            {ErrorReason::REDUNANT_CLOSE,  "There is redunant closing symbol."},
            {ErrorReason::INCORRECT_CLOSE,
             "There is incorrect closing symbol."                             }
    });

    const string TEST_STRINGS[] = {"{[()]}", "{}[(])}", "{([]()})]",
                                   "[}]{}(){"};
    for (const string& s : TEST_STRINGS) {
        OpenCloseGuard guard;
        GuardResult result = guard.check(&s);
        if (holds_alternative<Success>(result)) {
            cout << "\nString: " << s << " is valid." << endl;
        } else if (holds_alternative<GuardErrors>(result)) {
            cout << "\nString: " << s << " is ivvalid.\nFinded Errors:" << endl;
            auto errors = get<GuardErrors>(result);
            for (auto error : errors) {
                ErrorReason reason;
                ErrorString str;
                ErrorChar_or_nullptr charr;
                ErrorPosition position;
                tie(reason, str, charr, position) = error;
                char view_char = *charr ? **charr : '0';
                cout << "[ERROR]: " << (*POSSIBLE_ERRORS)[reason]
                     << " in string: " << s << " symbol:  " << view_char
                     << " on position: " << position << endl;
            }
        }
    }
    return 0;
}
