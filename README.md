# Jonathan Ho

This is a wordsearch puzzle solver. First, create a wordlist and a puzzle file and supply their filenames into the respective positions on lines 41 and 44. Also change the answer length constraints on lines 18 and 19 to match the given puzzle.

For this project, I used the C++ STL unordered_set (a hashtable) to store the wordlist. By using a hashtable, my program has constant insertion time when reading in the wordlist and constant lookup time when searching the puzzle. I used the C++ STL vector class for a vector of vectors of characters to store the puzzle grid. Last, I used the C++ STL set to store the answers of the wordsearch puzzle in alphabetical sorted order.

I know this is not the most time and space efficient solution to solving a wordsearch. Using tries is much more efficient than this brute force solution. My purpose for this program was to demonstrate my knowledge of hashtables in C++ and the unordered_set is one such implementation in the C++ STL. This program is also helpful for many puzzle competitions, such as the 2020 Harvard CS50X Puzzle Day Competition which had a word search puzzle (with some minor adjustments).

To compile the code, open terminal/command prompt to this directory and send the following command: "g++ -std=c++11 main.cpp student.cpp -o main". This will make an executable file called main.

After the code has compiled, you can execute the executable file that was just created by sending the following command: "./main".

This should run the program. To check the words in the wordlist that are present in the word search grid, simply open answer.txt.

## Sample Answers For The Provided Sample Puzzle (Constraint: Answers must be length 6+)
```
amelia from (235, 160) to (240, 160)
andric from (223, 112) to (228, 117)
aonach from (164, 196) to (164, 191)
autist from (199, 153) to (199, 158)
axwise from (98, 217) to (98, 222)
bairns from (221, 39) to (226, 44)
begobs from (199, 166) to (199, 161)
bhakti from (90, 135) to (85, 135)
bodgie from (127, 39) to (132, 34)
boldin from (233, 222) to (228, 217)
burton from (128, 54) to (123, 59)
calque from (210, 236) to (205, 236)
carole from (115, 162) to (115, 167)
coedit from (216, 106) to (216, 101)
combed from (120, 104) to (120, 99)
creamy from (164, 69) to (159, 74)
crosne from (29, 242) to (34, 247)
davies from (67, 179) to (72, 179)
digraph from (74, 144) to (80, 144)
durrie from (236, 241) to (231, 241)
engram from (16, 42) to (11, 37)
fizgig from (242, 189) to (237, 194)
gilour from (105, 213) to (100, 218)
guacos from (99, 215) to (94, 220)
herder from (117, 78) to (122, 78)
hicaco from (47, 211) to (47, 206)
intube from (68, 241) to (63, 246)
ipomea from (108, 113) to (103, 113)
jimjam from (87, 136) to (87, 141)
kohemp from (182, 130) to (187, 135)
lamaic from (211, 122) to (211, 117)
langca from (140, 193) to (145, 188)
loment from (158, 143) to (158, 138)
manser from (100, 175) to (95, 170)
misset from (57, 119) to (52, 119)
mummia from (199, 55) to (204, 55)
oozier from (166, 230) to (166, 225)
patener from (52, 25) to (46, 25)
planula from (62, 160) to (56, 154)
pluses from (64, 112) to (69, 112)
pooder from (166, 8) to (161, 13)
primas from (165, 121) to (170, 121)
rechar from (109, 213) to (114, 208)
riggal from (232, 173) to (237, 178)
rumdum from (90, 213) to (85, 208)
sovran from (208, 59) to (203, 54)
stated from (34, 64) to (34, 59)
stiles from (194, 23) to (194, 28)
supari from (199, 25) to (194, 25)
towery from (93, 152) to (88, 157)
tricks from (50, 202) to (45, 202)
undull from (225, 83) to (230, 83)
upwarp from (183, 229) to (178, 229)
usings from (18, 96) to (13, 91)
woofell from (228, 243) to (222, 237)
```
