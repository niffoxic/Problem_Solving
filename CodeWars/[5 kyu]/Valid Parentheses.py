def valid_parentheses(string):
    # your code here
    st = []
    for i in string:
        if i == '(':
            st.append(i)
        elif i == ')':
            if not len(st):
                return False
            st.pop()
    return not len(st)
