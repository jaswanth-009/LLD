Tic Tac Toe
 - 2 Players Game
 - Each player take alternate turns

Entities

Symbol
 - X
 - O
 - empty

Status
 - InProgress
 - Winner
 - Draw

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

Game
 - Board
 - Player1
 - Player2
 - winner
 - Status
 - Current Player
 - Winning Strategy
 - makeMove()
 - setWinningStrategy()
 - printBoard();


