
Gheorghe Marius Razvan 324CA

Problem 1 ----Servers----
To solve this problem, read the 2 power vectors
and power thresholds.
In order to find the value of the power supply, I chose to refer to the graph
making the difference between the vectors p and c and their sum for
to reduce the search interval on the graph to take positive values.
I did the maximum for the differences between c-p, the maximum on the left
and the minimum between c+p, the rightmost minimum and then I did the average 
the arithmetic between the 2 where we noticed that the optimal current is found
power supply or rather power.
The complexity is O(n) because they pass linearly through the vectors c and p.

Problem 2 ----Coloring----
To solve this problem, I will read the number of pairs again
I store them in a pair vector with number and type of numbers (H or V),
the functions will be of the long long type because we will work with quite a few values
large, that's why we have to use %MOD. The "powmod" function o 
I use for increasing the power in logarithmic time with the complexity of 
O(N*logn). In "get_result we will check the beginning of the chain of rectangles,
if it starts with H we will have 6 combinations for the first 2 overlapped rectangles
and the others in H format will remain 3^(n-1) color combinations. If it starts
with V the first rectangle will have 6 coloring possibilities and the following ones
they will have 2^(n-1) combinations, then after reading a pair we will check 
the next pair with the previous one to see how we get the combinations.
If the types remained as the previous ones, for V we leave 2^(n) and for H 3^(n),
and if the type changes between the present pair and the previous one for
V will be 2^(n-1) because the first V after H will come 1 and if it is H it will come
2*3^(n-1). The complexity of the algorithm is O(n) because they go through only one
given the vector of pairs.

Problem 3 ----Compression----
To solve this problem, I read the 2 vectors received at the input,
I go through the first vector and I will do the partial sums for it by storing them,
each one in a table. Then I go through the 2nd vector and keep it in a variable
temporary partial amount and I will check if it is in the table formed at 
traversing the first vector, I will do this search with a binary search,
for which I created the binary_search function.
In terms of complexity, the algorithm runs through both vectors linearly, so it will be
complexity in O(N).

Problem 4 ----Encrypted----
To solve this problem I will use something similar to the problem
of the backpack when I have to find the maximum length of the password, browsing
decreasing in order not to count a preceding word several times.
I will read all the words in a words vector, I will do the frequency
for each letter in each word and I will store them in a map
N times for each word.
Then I go through every possible letter and get all the password combinations
of maximum length for the respective letter, doing so as follows:
I take a dp vector of the maximum length of the password 10001, it goes through all of them
the words to the respective letter, the length and frequency of the letter in that one is taken
word, the vector is traversed from the end so as not to add a longer length
many times then I check if the maximum condition is met, that is, I do the maximum
between the current length and the length + frequency of the dominant letter.
Then I check if the number of occurrences of the letter is greater than half
from the length of the password.
The complexity is O(26*10000*N) because I go through all of them for each letter
the words and the lengths go on.

Problem 5 ----Offer----
To solve this problem we used the notion of dynamic programming,
using a cost vector "cost" used to store the minimum required
the purchase of those in the products.
I can take the product alone, in the format of 2 or 3.
I alone add the price of the product to the calculated total cost.
Two products, I check if by buying the 2 together 
and with a discount it's cheaper if I buy separately, or if
I buy 3 products (2 most expensive and the 3rd cheap) I will calculate
the most expensive 2 out of 3 and I will compare.
So the cost will be the minimum that I calculate in the decision structure.
The complexity of the algorithm will be O(n) because I will loop through all the elements
vector and I will only do O(1) checks inside the traversal.

