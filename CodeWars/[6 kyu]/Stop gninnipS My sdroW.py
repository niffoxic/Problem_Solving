# It's been a year I coded problem solution in py T_T
# slow code T_T but working

def spin_words(sentence):
    t = sentence.split()
    res = []
    for i in t:
        if len(i) >= 5:
            res.append(i[::-1])
        else:
            res.append(i)
    return " ".join(res)
 # TOOOO BAD
