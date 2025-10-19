## SnakeAndLadder

-> MultiplayerGame
-> Minimum 2 players are required
-> Board size should be configurable
-> Snakes and Ladders must be configurable
-> Dice can be extensible
-> Dice mst generate outcomes randomly

## Entities

### Player
 - name
 - position
 - getName()
 - getPosition()
 - setPosition()

### Dice
 - minVal
 - maxVal
 - rollDice()

### Board
 - boardSize
 - list of snakes and ladders
 - final position values considering snakes and ladders
 - getBoardSize()
 - getFinalPosition()

### BoardEntitty
 - startPosition
 - endPosition
 - virtual arePositionsValid()

### Snake -> BoardEntity
 - arePositionsValid()

### Ladder -> BoardEntity
 - arePositionsValid

### State
 - InProgress
 - Winner

### Game
 - board
 - players
 - dice
 - winner
 - state
 - getWinner()
 - setWinner()
 - play()
 - setState()
 - getState()
 - generateHash()