This is a C++ implementation of tic-tac-toe. It follows all the rules of the game and has a (rather dumb) AI. I set to do this project with the minimax algorithm, but it became too time consuming and I ran into some internet limitations while traveling so I couldn't really research minimax much. So instead I used a random number generator for the AI to just randomly pick an available move. It's super easy to win, kind of hard to get a tie, but making it hard isn't really the point of this project, I just wish I were in a higher level course.

It is structed with two classes. One to handle game mechanics, and one to handle the mechanics of the board. This might seem confusing, but the board object handles the board, while the game object handles higher-level things like reading the config file, AI, and handling user input.

A game goes like this: It prints the board then prompts the user for input. It makes the user move and instantly makes an AI move as well, then prints the board again. it repeats this until someone wins or there is a tie. At the end, a log of every move is output to log.txt

images (featuring my self-hosted url shortener/image host):

game in action - http://in4.us/kleU
log file - http://in4.us/o8Gz5s
config file - http://in4.us/Tmjpmw
