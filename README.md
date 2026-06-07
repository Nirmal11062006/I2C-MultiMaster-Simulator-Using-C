# I2C-MultiMaster-Simulator-Using-C
A modular I2C communication simulator in C featuring multi-master arbitration, memory slave, FIFO queue slave, LIFO stack slave, bus ownership management, and Makefile-based project structure.
# I2C Multi-Master Multi-Slave Simulator Using C

## Overview

This project is a software simulation of the I2C (Inter-Integrated Circuit) communication protocol written in C.

The simulator demonstrates how multiple masters communicate with different slave devices through a shared I2C bus while handling bus ownership, arbitration, and data transfer operations.

The project is implemented using a modular design with separate source and header files for each component.

---

## Features

### Multi-Master Support

* Two I2C masters
* Bus ownership management
* Master selection at runtime
* Bus acquisition and release operations

### Arbitration Simulation

* Simulates I2C multi-master arbitration
* Detects arbitration loss
* Prevents simultaneous bus access

### Slave Devices

#### Memory Slave

* Read data from memory locations
* Write data to memory locations
* Configurable slave address

#### FIFO Slave (Queue)

* Enqueue operation
* Dequeue operation
* FIFO full and empty detection

#### LIFO Slave (Stack)

* Push operation
* Pop operation
* Stack full and empty detection

### Bus Management

* SDA and SCL simulation
* Bus busy status
* Current master tracking
* Slave registration to the bus

---

## Project Structure

```text
I2C-MultiMaster-MultiSlave-Simulator/
│
├── include/
│   ├── status.h
│   ├── i2c_bus.h
│   ├── master.h
│   ├── memory_slave.h
│   ├── fifo_slave.h
│   └── lifo_slave.h
│
├── src/
│   ├── main.c
│   ├── i2c_bus.c
│   ├── master.c
│   ├── memory_slave.c
│   ├── fifo_slave.c
│   └── lifo_slave.c
│
├── Makefile
└── README.md
```

---

## Build

```bash
make
```

---

## Run

```bash
./i2c_simulator
```

---

## Menu Options

```text
1. Acquire Bus
2. Release Bus
3. Memory Write
4. Memory Read
5. FIFO Enqueue
6. FIFO Dequeue
7. LIFO Push
8. LIFO Pop
9. Bus Status
10. Exit
```

---

## Sample Arbitration

```text
Master 1 -> Acquire Bus
Bus Acquired

Master 2 -> Acquire Bus
Arbitration Lost

Master 1 -> Release Bus
Bus Released

Master 2 -> Acquire Bus
Bus Acquired
```

---

## Concepts Demonstrated

* I2C Protocol Fundamentals
* Multi-Master Communication
* Arbitration Mechanism
* Bus Ownership
* Queue (FIFO) Data Structure
* Stack (LIFO) Data Structure
* Modular Programming in C
* Header File Organization
* Makefile Based Build System

---

## Future Improvements

* I2C Start and Stop Condition Simulation
* ACK/NACK Handling
* Logger Module
* Dynamic Slave Registration
* Command Line Arguments
* Timing Simulation
* Multiple Memory Slaves

---

## Author

Nirmal

Developed as a learning project to understand I2C communication, embedded systems concepts, data structures, and modular programming in C.
