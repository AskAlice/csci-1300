# CS1300 Fall 2017
# Author: 
# Recitation: 
# Assignment 10


#PART_1 functions here

#PART_2 follow here


class Recommender:
	def __init__(self, name):
    		self.name = name
    		self.books = []

    #Constructor here
	def read_books(self,filename):
	    l = []
	    for line in open(filename):
	        line.rstrip('\n')
	        s = [x.strip() for x in line.split(',')]
	        l.append([s[0], s[1]])
	    	self.books = l
	    return None

	def read_users(self, file_name):
		"""
		"""
		return None

	def calculate_average_rating(self):
		"""
		"""
		return

	def lookup_average_rating(self, book_index):
		"""
		"""
		return average_rating_string

	def calc_similarity(self, user1, user2):
		"""
		"""
		return similarity_measure

	def get_most_similar_user(self, current_user_id):
		"""
		"""
		return best_user_match_id

	def recommend_books(self, current_user_id):
		"""
		"""
		return recommendations_list


def main():
    #test your functions and classes here
    r = Recommender('Alice')
    print(r.read_books('book.txt'));

if __name__ == "__main__":
    main()