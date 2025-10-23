## Parking Lot System

 - 3 types of slots -> Compact, Medium, Large
 - Multiple floors must be supported
 - Multi threading must be supported as each floor can have multiple entry points
 - Ticket Generation must be handled -> strategies can vary


### Entities

### VehicleType
 - Bike
 - MiniCar
 - HatchBack
 - SUV

### Vehicle
 - vehicleNumber
 - vehicleType

### Parking Type
 - Compact
 - Medium
 - Large

### ParkingLot
 - ParkingType
 - Vehicle
 - isEmpty()
 - timeStamp
 - parkVehicle()
 - unparkVehicle()

### ParkingTicket
 - Vehicle
 - ParkingLot
 - entry time
 - exit time

### ParkingFloor
 - vector of ParkingLots
 - list of parked vehicles
 - count of available slots and filled slots
 - map of parking tickets for parked vehicles
 - fee strategy
 - addSlot()
 - parkVehicle()
 - unparkVehicle()
 - setFeeStrategy()
 - isVehiclePresent()


### FeeStrategy
 - virtual calculateFees()

### FixedFeeStrategy -> FeeStrategy
 - calculateFees()

### TimeBasedFeeStrategy -> FeeStrategy
- calculateFees()


