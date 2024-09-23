#include <stdio.h>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int maxAnd = 0;
    int maxOr = 0;
    int maxXor = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            int OR = j | i;
            int AND = j & i;
            int XOR = j ^ i;
            if(AND < k) maxAnd = (maxAnd > AND) ? maxAnd : AND;
            if(OR < k) maxOr = (maxOr > OR) ? maxOr : OR;
            if(XOR < k) maxXor = (maxXor > XOR) ? maxXor : XOR;
        }
    }
    printf("%d\n", maxAnd);
    printf("%d\n", maxOr);
    printf("%d\n", maxXor);
    return 0;
}
