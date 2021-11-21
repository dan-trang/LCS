# LCS
The repo contains both the brute-force as well as dynamic programming method of solving the longest common subsequence (LCS) of two strings.
The dynamic programming implementation is a bottom-up approach wherein a table (really a 2D array) is filled with solutions to the subproblems
from recursion. As the recursion unwinds, a compare-to-find-maximum function will recall elements from the table as to cut down execution time.

Both the run time, space efficiency and theoretical vs. experimental will be analyzed in a seperate write up document. For now, this GitHub repo
will contain the source code and be used to track changes made.
