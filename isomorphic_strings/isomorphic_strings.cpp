//38ms
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, size_t> visited;

        for (size_t i = 0; i < s.size(); ++i)
        {
            if (visited.find(s[i]) != visited.end())
            {
                continue;
            }
            ++visited[s[i]];
            size_t pos_s = i;
            size_t pos_t = i;

            while (pos_s != string::npos and pos_t != string::npos)
            {
                pos_s = s.find_first_of(s[i], pos_s + 1);
                pos_t = t.find_first_of(t[i], pos_t + 1);

                if (pos_s != pos_t)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//from leetcode discussion, only 8ms
/*class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        const size_t n = s.size();
        if ( n != t.size())
            return false;

        unsigned char forward_map[256] = {}, reverse_map[256] = {};

        for ( int i=0; i < n; ++i)
        {
            unsigned char c1 = s[i];
            unsigned char c2 = t[i];

            if ( forward_map[c1] && forward_map[c1] != c2)
                return false;

            if ( reverse_map[c2] && reverse_map[c2] != c1)
                return false;

            forward_map[c1] = c2;
            reverse_map[c2] = c1;
        }

        return true;
    }
};*/
