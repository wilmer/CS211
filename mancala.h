class Board 
{ 
  static const int NUMSTONES = 4;  // number of stones each bowl begins with 
  static const int NUMBOWLS = 6;   // number of bowls for each player 
                                   // (count does not include the mancala) 
public: 
  Board(); 
  // post: All bowls for each player have been initialized to NUMSTONES. 
  //   The mancala for each player has been initialized to 0. 

  void setFirstPlayer(const char color, const bool compPlayer); 
  // pre: color = 'R' or 'B'. 
  // post: The current player is set to the value passed in to the variable 
  //   color.  (This function should only be called once per round -- 
  //   prior to the first move.) 

  char checkForWin(); 
  // post: Returns 'R' if the Red player has won 
  //   Returns 'B' if the Blue player has won 
  //   Returns 'N' if neither player has won 

  bool move(const int bowlNum, const int direction); 
  // pre: bowlNum = the starting bowl the current player will move from 
  //   (specified by an int between [0,NUMBOWLS-1]). 
  //   direction = -1 (for clockwise) or 1 (for counter clockwise) 
  // post: The human player's move is executed, and the current player is 
  //   updated/switched.  If the player's move wins him/herself another  
  //   turn, the function returns true.  Otherwise, the function returns  
  //   false. 

  bool computerMove(); 
  // pre: currPlayer = The computer player's color. 
  // post: The computer player executes a move according to its strategy 
  //   (described below).  The current player is updated/switched.  If the 
  //   the computer's move wins itself another turn, the function returns  
  //   true.  Otherwise, the function returns false. 

  void display(); 
  // post: The current mancala board status has been printed to the screen. 

  friend std::ostream& operator << (std::ostream& outs, const Board& obj); 
  // post: The board contained in obj has been printed to the ostream 
  //   (in whatever format you choose). 

  friend std::istream& operator >> (std::istream& ins, Board& obj); 
  // post: board is read from istream and stored in object obj. 

private: 
  int theBoard[2][NUMBOWLS+1];  // Each row is one player's side of the 
                                // board.  Indices [0,NUMBOWLS-1] represent 
                                // a player's bowls.  NUMBOWLS represents  
                                // a player's mancala. 
  char currPlayer;  // The color of the current player 

  void switchPlayers(); 
  // pre: It is the end of one player's turn 
  // post: currPlayer is updated to indicate it is a different player's turn 

  void addToMancala(); 
  // pre: The current player just ended his turn by placing a stone 
  //   in one of his empty bowls. 
  // post: The newly placed stone, plus all of the stones from the  
  //   opponent's corresponding bowl, are added to the current player's 
  //   mancala. 
}; 

class Mancala 
{ 
public: 
  Mancala(); 
  // pre: Random Number Generator (RNG) has been seeded. 
  // post: The player to move first (Red or Blue) has been chosen. 

  bool LoadGame(); 
  // post: User is asked for a file to open that stores a previously saved 
  //   game.  If the file exists and is in the correct format, the game is 
  //   loaded and True is returned.  Else the function returns false. 

  void SaveGame(); 
  // post: The user is prompted for a filename, and the current game is 
  //   saved to the file. 

  char Play(); 
  // post: This function allows two people to play a round of Mancala.  If 
  //   the Red player wins, 'R' is returned.  If the Blue player wins, 'B' 
  //   is returned.  If there is a tie, 'T' is returned. 

private: 
  Board gameBoard;    // the Mancala board containing all the stones 

  char currPlayer;    // the color of the player whose turn it is 
}; 

