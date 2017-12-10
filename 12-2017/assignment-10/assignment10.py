# CS1300 Fall 2017
# Author: Alice Knag 
# Recitation: CSCI 1300-210 X. Zhang Thurs 5pm
# Assignment 10



#PART_1 functions here
def read_books(filename):
        l = []
        try:
            for line in open(filename):
                line.rstrip('\n')
                s = [x.strip() for x in line.split(',')]
                l.append([s[1], s[0]])
        except IOError:
            return None
        return l
def read_users(filename):
    u = {}
    try:
        for line in open(filename):
            line.rstrip('\n')
            s = [x.strip() for x in line.split(' ')]
            ints = []
            for a in s[1:]:
                try:
                    ints.append(int(a))
                except:
                    pass
            u[s[0]] = ints
    except IOError:
        return None
    return u

def calculate_average_rating(d):
    bookRatings = []
    allRatings = []
    averages = []
    size = 0;
    for k,v in d.items():
        ratings = []
        for i,b in enumerate(v):
            ratings.append(b)
            if i > size:
                size = i
        allRatings.append(ratings)
    bookRatings = [[] for _ in range(size+1)]
    for l in allRatings:
        for i,b in enumerate(l):
                if b != 0:
                    bookRatings[i].append(b)
    for b in bookRatings:
        averages.append((float(sum(b))/float(len(b))))
    return averages

def lookup_average_rating(i,b,r):
    return "(%s) %s by %s" % (format(round(r[i],2),".2f"),b[i][0],b[i][1])
#PART_2 follow here


class Recommender:
    def __init__(self, b, u):
            self.books = []
            self.users = {}
            self.averages = []
            self.read_books(b)
            self.read_users(u)

    #Constructor here
    def read_books(self,filename):
        try:
            for line in open(filename):
                line.rstrip('\n')
                s = [x.strip() for x in line.split(',')]
                self.books.append([s[1], s[0]])
        except IOError:
            pass
        return None

    def read_users(self,filename):
        try:
            for line in open(filename):
                line.rstrip('\n')
                s = [x.strip() for x in line.split(' ')]
                ints = []
                for a in s[1:]:
                    try:
                        ints.append(int(a))
                    except:
                        pass
                self.users[s[0]] = ints
        except IOError:
            pass
        return None

    
    def calculate_average_rating(self):
        d = self.users;
        self.averages = []
        bookRatings = []
        allRatings = []
        averages = []
        size = 0;
        for k,v in d.items():
            ratings = []
            for i,b in enumerate(v):
                ratings.append(b)
                if i > size:
                    size = i
            allRatings.append(ratings)
        bookRatings = [[] for _ in range(size+1)]
        for l in allRatings:
            for i,b in enumerate(l):
                    if b != 0:
                        bookRatings[i].append(b)
        for b in bookRatings:
            self.averages.append((float(sum(b))/float(len(b))))
        return None


    def lookup_average_rating(self,i):
        return "(%s) %s by %s" % (format(round(self.averages[i],2), '.2f'),self.books[i][0],self.books[i][1])

    def calc_similarity(self, user1, user2):
        sum = 0.0;
        for i,r in enumerate(self.users[user1]):
                sum += r * self.users[user2][i]
        return sum

    def get_most_similar_user(self, current_user_id):
        best = 0;
        bestu = 0;
        for k,r in self.users.items():
            if k != current_user_id:
                sim = self.calc_similarity(current_user_id, k)
                if sim > best:
                    best = sim
                    bestu = k
        return bestu

    def recommend_books(self, current_user_id):
        rec = []
        u = self.get_most_similar_user(current_user_id)
        for i,b in enumerate(self.users[u]):
            if self.users[current_user_id][i]:
                s = self.lookup_average_rating(i)
                rec.append(s)
        return rec

def test():
    book_list = read_books("book.txt")
    user_dict = read_users("ratings.txt")

    ### Test case for the part 1
    ave_rating_list = calculate_average_rating(user_dict)
    print round(ave_rating_list[0], 3)  # 3.833
    print ave_rating_list[20]       # 0.5
    print lookup_average_rating(0, book_list, ave_rating_list)
    # (3.83) The Hitchhiker's Guide To The Galaxy by Douglas Adams

    
    ### Test case for part 2
    r = Recommender("book.txt", "ratings.txt")
    r.calculate_average_rating()
    print(r.averages)
    
    #### calc_similarity function:
    print r.calc_similarity('Cust8', 'Shannon')      # 369
    print r.calc_similarity('Megan', 'Strongbad')    # 95
    print r.calc_similarity('Leah', 'clipper')       # 0
    print r.calc_similarity('Apollo', 'James')       # -65


    #### lookup_average_rating function
    print r.lookup_average_rating(0)            # (3.83) The Hitchhiker's Guide To The Galaxy by Douglas Adams
    print r.lookup_average_rating(7)            # (0.43) The Sisterhood of the Travelling Pants by Ann Brashares
    print r.lookup_average_rating(17)           # (2.38) Neuromancer by William Gibson
    print r.lookup_average_rating(30)           # (1.77) To Kill a Mockingbird by Harper Lee
    print r.lookup_average_rating(54)       # (1.56) The Chrysalids by John Wyndham
    print r.lookup_average_rating(10)       #(0.90) The Princess Diaries by Meg Cabot-> it should be (0.90), NOT (0.9)   

    #### get_most_similar_user
    print r.get_most_similar_user("Leah")       # hidan
    print r.get_most_similar_user("Rudy_Ann")   # ROFLOL
    print r.get_most_similar_user("Martin")     # clipper
    print r.get_most_similar_user("KeeLed")     # Cust8
    print r.get_most_similar_user("Rudy.A")     # Cust8


    #### recommend_books
    print r.recommend_books("Brian")
    # []
    print r.recommend_books("Megan")
    # ['(0.90) The Princess Diaries by Meg Cabot',
    #  "(3.80) My Sister's Keeper by Jodi Picoult",
    #  '(2.06) Bone Series by Jeff Smith']
    print r.recommend_books("Tiffany")
    # ['(3.86) The Bourne Series by Robert Ludlum']
    print r.recommend_books("Moose")
    # ['(3.50) The Princess Bride by William Goldman',
    #  '(3.86) The Bourne Series by Robert Ludlum',
    #  '(0.47) Twilight Series by Stephenie Meyer',
    #  '(2.76) The Golden Compass by Philip Pullman',
    #  '(3.57) Holes by Louis Sachar']
    print r.recommend_books("Ella")
    # ["(3.83) The Hitchhiker's Guide To The Galaxy by Douglas Adams",
    #  '(2.25) The Da Vinci Code by Dan Brown',
    #  '(1.62) Naruto by Masashi Kishimoto',
    #  '(3.86) The Bourne Series by Robert Ludlum',
    #  "(3.80) My Sister's Keeper by Jodi Picoult",
    #  '(3.61) Harry Potter Series by J.K. Rowling',
    #  '(2.06) Bone Series by Jeff Smith',
    #  '(3.04) The Lord of the Rings by J R R Tolkien',
    #  '(2.85) The Hobbit by J R R Tolkien',
    #  '(2.83) The War Of The Worlds by H G Wells']
    

if __name__ == "__main__":
    test()