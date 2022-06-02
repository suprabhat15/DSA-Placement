House Robber is typical example of subsequences problems with "pick & not-pick" technique.
We need to use Recursion to try out every single possibility.
On noticing things properly,
f(5)
/      \
f(3)      f(4)
/     \      /   \
f(1)    f(2)  f(2) f(3)
Here, f(2), f(3) are getting repeated => Overlapping => Hence, DP.
​
So, Memoization needs to be used with Recursion.