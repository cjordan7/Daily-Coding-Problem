
import Foundation

func resolveProblem001(_ array: [Int], _ k: Int) -> Bool {
    var tempSolutions = Set<Int>()
    
    for number in array {
        if(tempSolutions.contains(number)) {
            return true
        }
        
        tempSolutions.insert(k - number)
    }

    return false
}

func test() {
    let test1 = [1, 2, 3, 4, 5, 6, 7]
    assert(resolveProblem001(test1, 13));
    assert(resolveProblem001(test1, 12));
    assert(!resolveProblem001(test1, 14));
    assert(!resolveProblem001(test1, 1));
}

test()
