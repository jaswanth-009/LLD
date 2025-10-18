Tic Tac Toe
 - 2 Players Game
 - Each player take alternate turns

Entities

Symbol
 - X
 - O
 - empty

State
 - InProgress
 - Winner
 - Draw
 - makeMove()

InProgressState --> State
WinnerState     --> State
DrawState       --> State

Player
 - name
 - symbol
 - getSymbol()
 - getName()

Cell
 - symbol
 - isEmpty()
 - getSymbol()
 - setSymbol()

Board
 - size
 - movesCount
 - 2D matrix of Cells
 - placeSymbol()
 - printBoard()
 - getBoardSize()
 - getCell()
 - getMovesCount()

Winning Strategy
 - isWinner()

WinningStrategy Types
 - RowBased
 - ColumnBased

GameSubject
 - observers
 - addObserver()
 - removeObserver()
 - notifyObservers()

GameObserver
 - update();

Game -> GameSubject
 - Board
 - Player1
 - Player2
 - winner
 - State
 - Current Player
 - Winning Strategy
 - getBoard()
 - makeMove()
 - setWinningStrategy()
 - printBoard()
 - setCurrentPlayer()
 - swicthPlayers()
 - checkWinner()
 - setState()
 - getCurrentPlayer()
 - getWinnerState()
 - getDrawState()
 - generateHash()
 - getUid()

TicTacToeSystem --> Singleton
 -> Can Manage multiple Games
 - createGame()
 - makeMove()
 - printScoreBoard()


Scoreboard -> GameObserver
 - scores
 - update()
 - printScores()