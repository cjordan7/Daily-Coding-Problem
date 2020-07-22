
def resolveProblem001(array, k):
    tempSolutions = set()

    for i in array:
        if(i in tempSolutions):
            return True
        else:
            tempSolutions.add(k - i)


def test():
    test1 = [1, 2, 3, 4, 5, 6, 7]
    assert(resolveProblem001(test1, 13))
    assert(resolveProblem001(test1, 12))
    assert(not resolveProblem001(test1, 14))
    assert(not resolveProblem001(test1, 1))


test()
