# Author: Alice Knag
# Recitation: CSCI 1300-210 X. Zhang
#
# Assignment 9
# assignment9.py

#basic math. rates is a list, pop is an int.
def compute_census(rates, pop):
    secondsInYear = 86400*365
    bornInYear = secondsInYear / rates[0]
    deathsInYear = secondsInYear / rates[1]
    immigrantsInYear = secondsInYear / rates[2]
    return (pop + bornInYear + immigrantsInYear - deathsInYear)


def convert_seconds():
    sec = input("Enter the amount of seconds you want to convert? ")
    sec = int(sec)
    print
    days = sec / 60 / 60 / 24
    hours = sec / 60 / 60 % 24
    minutes = sec / 60 % 60
    seconds = sec % 60
    print("%s corresponds to: %s days, %s hours,"
          " %s minutes, %s seconds." % (sec, days, hours, minutes, seconds))
          # linebreak for PEP8 line size requirements

#this works with any size list, as long as it ends with a string and not a prompt string. Passes cog.
def generate_story(l):
    inputs = []
    strings = []
    string = ""
    for index, item in enumerate(l):
        if(index % 2):
            inputs.append(raw_input(item))
        else:
            strings.append(item)
    for index, s in enumerate(strings):
        try:
            string += s + " " + inputs[index] + " "
        except:
            string += s + "."
    return string

#uses zip to iterate through vaues of each sequence (strings), then if they're not equal, it returns true, and adds 1 to it. As it loops through, the sum gets added as difference increases.
def similarity_score(seq1, seq2):
    if not len(seq1) == len(seq2):
        return 0
    l = len(seq1)
    dist = sum(c1 != c2 for c1, c2 in zip(seq1, seq2))
    return float(float(l - dist)/l)

#it iterates through possible positions of the sequence on the genome, if the score is greater than the best, the index is recorded and later returned.
def best_match(genome, seq):
    bestScore = 0.0
    bestIndex = 0
    for index, s in enumerate(genome):
        score = similarity_score(genome[index:index+len(seq)], seq)
        if(score > bestScore):
            bestScore = score
            bestIndex = index
    return bestIndex

#finds the median with this logic, the average is sum/length
def calc_stats(l):
    l.sort()
    ll = len(l)
    if not ll % 2:
        return [(sum(l)/float(ll)), ((l[ll / 2] + l[ll / 2 - 1]) / 2.0)]
    return [(sum(l)/float(ll)), l[ll / 2]]


#it loops through each line, strips out the endline, then strips commas, then it strips spaces for the text to the right of the comma.
#then creates the nested list with append.
def parse_ratings(filename):
    l = []
    for line in open(filename):
        line.rstrip('\n')
        s = [x.strip() for x in line.split(',')]
        i = [int(x.strip()) for x in s[1].split(' ')]
        l.append([s[0], i])
    return l

#test functions
def main():
    rates = [8, 12, 33]
    print(compute_census(rates, 10000000))
    convert_seconds()
    list_to_story = ["I went skiing to", "Enter a location: ",
                     "it was really crowded and I stayed in line for",
                     "Enter number of hours: ", "hours"]
    print(generate_story(list_to_story))
    print("sscore: " + str(similarity_score("CCGCCGCCGA", "CCTCCTCCTA")))
    print("bestMatch: " + str(best_match("yyyxxxyyy", "xxx")))
    l = [1, 2.5, 3, 8, 10.5, 5]
    print("calc_stats: mean: " + str(calc_stats(l)[0]) +
          " | median: " + str(calc_stats(l)[1]))
    print(parse_ratings("ratings.txt"))


if __name__ == '__main__':
    main()
