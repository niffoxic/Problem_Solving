class Solution:
    def isValid(self, s: str) -> bool:
        stack = list()
        for i in s:
            if i in "([{":
                stack.append(i)
            else:
                if any([(stack and i == '}' and stack[-1] == '{'),
                        (stack and i == ']' and stack[-1] == '['),
                        (stack and i == ')' and stack[-1] == '(')]):
                    stack.pop()
                else:
                    return False
        return len(stack) == 0
