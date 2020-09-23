
#include <iostream>
#include <functional>
#include <assert.h>;


int main(int argc, char** argv) {
    // cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first
    // and last element of that pair.

    auto cons = [](auto a, auto b) {
                    return [a, b](auto f) {
                               return f(a, b);
                           };
                };

    auto car = [](auto f) {
                   auto e = [](auto x, auto y) {
                                return x;
                            };
                   return f(e);
               };

    auto cdr = [](auto f) {
                   auto e = [](auto x, auto y) {
                                return y;
                            };
                   return f(e);
               };

    assert(car(cons(1, 2)) == 1);
    assert(cdr(cons(1, 2)) == 2);

    return 0;
}
