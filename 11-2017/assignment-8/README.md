This is a C++ implementation of the minimax algorithm in tic tac toe so that the user can never win. They can only tie or lose. It uses a full tree search to try every possible move, score them accordingly, then use the best possible move. I'm super bored in this class so I decided to actually challenge myself.

It is structed with two classes. The Board class to handle board array, mechanics of valid moves, and logging. And the Game class to handle the game mechanics of the AI, handling user input, reading config files.

A game goes like this: It prints the board then prompts the user for input. It makes the user move, scores every possible move to make the best AI move, then prints the board again. it repeats this until someone wins or there is a tie. At the end, a log of every move is output to log.txt

images (featuring my self-hosted url shortener/image host):

game - http://in4.us/spM
log file - http://in4.us/rQB
config file - http://in4.us/Tmjpmw