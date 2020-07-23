
#import <Foundation/Foundation.h>


bool resolveProblem001(NSArray* array, int k) {
    NSMutableSet* tempSet = [NSMutableSet set];
    
    for(int i = 0; i < [array count]; ++i) {
        NSInteger element = [[array objectAtIndex:i] integerValue];
        if([tempSet containsObject:@(element)]) {
            return true;
        } else {
            [tempSet addObject:@(k - element)];
        }
    }
    
    return false;
}

void test() {
    NSArray* test1 = [NSArray arrayWithObjects:@1, @2, @3, @4, @5, @6, @7, nil];

    assert(resolveProblem001(test1, 13));
    assert(resolveProblem001(test1, 12));
    assert(!resolveProblem001(test1, 14));
    assert(!resolveProblem001(test1, 1));

}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        test();
    }
    return 0;
}
