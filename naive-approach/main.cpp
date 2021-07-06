#include <bits/stdc++.h>

/* brute-force algorithm for string matching */
int32_t string_matching(std::string& text, std::string& pattern) {

    /* length of text string */
    int32_t N{(int32_t)text.length()};

    /* length of pattern string */
    int32_t M{(int32_t)pattern.length()};

    for (int32_t i{0}; i < N - M + 1; i++) {
        bool is_matched{true};

        /* check whether or not text[i..i+M]
         * and pattern[0..M-1] are equal */
        for (int32_t j{0};j < M;j++) {
            if (text[i+j] != pattern[j]) {
                is_matched = {false};break;
            }
        }

        /* if exact match has been found */
        if (is_matched) {return i;}
    }

    /* -1 sentinel is used to indicate that
     * pattern doesn't exist in text string */
    return -1;
}

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    /* text & pattern string */
    std::string text;std::cin >> text;
    std::string pattern;std::cin >> pattern;

    /* string matching algorithm */
    double start{static_cast<double>(clock())};
    int32_t index {string_matching(text, pattern)};
    double end{static_cast<double>(clock())};

    /* calculate processing time for string matching */
    double time_required{(end - start)/CLOCKS_PER_SEC};
    std::cout << "Required time: " << time_required << " sec" << std::endl;

    /* print based on whether or not pattern been found */
    if (index != -1) {
        std::cout << "first occurrence of pattern \"" << pattern ;
        std::cout << "\" is at position " << (index + 1) << std::endl;
    } else {
        std::cout << "pattern string \"" << pattern << "\" not found!" << std::endl;
    }
    return 0;
}