#include <bits/stdc++.h>

/* find out z_value of k-th index */
int32_t zValue(std::string& s, int32_t k) {
    int32_t zValueOf_i{0};

    while (zValueOf_i + k < s.length()) {
        /* longest substring starting at
         * k which is prefix of string s */
        if (s[zValueOf_i] == s[zValueOf_i + k]) {
            zValueOf_i += 1;
        } else {
            /* if characters aren't equal
             * at corresponding positions */
            break;
        }
    }
    return zValueOf_i;
}

void create_z_array(std::vector<int32_t>& zArray, std::string& s) {
    /* z-value for first character */
    zArray[0] = 0;int32_t i{1};
    while (i < s.length()) {
        zArray[i] = {zValue(s, i)};

        if (zArray[i] > 1) {
            /* z_box boundary */
            int32_t left{i}, right{zArray[i] + i - 1};

            /* copy z_box_values */
            for (int32_t j{left + 1};j <= right;j++) {
                /* zArray[j-left]: corresponding prefix's zValue */
                if ((zArray[j - left] + j) > right) {
                    /* calculate zArray[j]'s value if
                     * z_value might have greater value */
                    zArray[j] = zValue(s, j);
                } else {
                    /* copy corresponding z_value */
                    zArray[j] = zArray[j - left];
                }

                /* update value of i */i += 1;
            }
        }
        i += 1;
    }
}

/* Z-Algorithm for string matching */
void string_matching(std::string& text, std::string& pattern) {

    /* length of text string */
    int32_t N{(int32_t)text.length()};

    /* length of pattern string */
    int32_t M{(int32_t)pattern.length()};

    /* create string for pattern_matching */
    std::string s{pattern + "$" + text};

    /* Z-array */
    std::vector<int32_t> z_array(N + M + 1);

    /* create z-array */
    create_z_array(z_array, s);

    /* linear-search-algorithm */
    for (int32_t i{M+1};i < (N+M+1);i++) {
        if (z_array[i] == M) {
            std::cout << (i - M - 1) << "\n";
        }
    }
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
    string_matching(text, pattern);
    double end{static_cast<double>(clock())};

    /* calculate processing time for string matching */
    double time_required{(end - start)/CLOCKS_PER_SEC};
    std::cout << "Required time: " << time_required << " sec" << std::endl;
    return 0;
}