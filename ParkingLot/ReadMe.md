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

### ParkingFloor
 - vector of ParkingLots
 - parkVehicle()
 - unparkVehicle()

### PricingStrategy
 - virtual calculateFees()

### FixedPricingStrategy -> PricingStrategy
 - calculateFees()

### TimeBasedPricingStrategy -> PricingStrategy
- calculateFees()


