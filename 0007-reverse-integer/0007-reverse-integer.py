class Solution:
    def reverse(self, x: int) -> int:
        s=str(abs(x))
        reversed=int(s[::-1])
        if reversed>2**31 - 1:
            return 0

        return reversed if x>0 else (reversed*-1)
