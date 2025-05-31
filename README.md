# Cpp_t_contest
This repository contains 10 C++ programs solving various algorithmic problems. 

These algorithms have real-world applications. Take a look below 👇
## Used Techniques

    Binary search (polygonal_pie.cpp)
    Graph theory (secret_santa.cpp)
    Dynamic programming (free_lunch.cpp)
    Geometric algorithms (conference_room.cpp)
    Greedy approaches (maximizeSum.cpp)
    
## Compilation and Execution
All programs are standard C++ and can be compiled with c++
# Compilation and Run (example)
c++ secret_santa.cpp
./secret_santa

Below is a detailed breakdown of each program.
## 1. mobile.cpp
Calculates final cost based on base price, actual (or average) usage and price usage exceeds included limit.
Details:

    Simple conditional arithmetic
    Practical Use:
    1. Telecom billing systems calculating data charges
    2. Cloud service pricing models with included/extra resource thresholds
    3. Utility billing systems (electricity/water) with base allowances
    
## 2. pie.cpp
Calculates how many times a number can be halved before every parting reached 1.
Details:

    Simple iterative algorithm with integer division
    Logarithmic reduction
    Practical Use:
    1. Tournament systems calculating elimination rounds to determine a winner which helps schedule match timing and court/dates allocations
    2. Computer network protocols determining optimal packet fragmentation thresholds when sending a 1000-byte file through a network with 300-byte maximum packets (the algorithm calculates it needs 4 transmissions: 300*3 + 100)  
    3. Game theory models for divide-and-choose fair division problems, where parties alternate being divider/chooser
    
## 3. ladder.cpp
Optimizes elevator movement in a multistory building to the minimal travel time for picking up/dropping off passengers at different floors.
Details:

    Compares multiple route options
    Considers time constraints
    Practical Use:
    1. High-rise emergency evacuation route optimization
    2. Warehouse logistics for optimal goods elevator scheduling
    3. Hospital bed elevator prioritization during peak hours
    
## 4. maximizeSum.cpp
Calculates maximum possible sum gain by replacing digits (up to allowed moves).
Details:

    Digit decomposition and greedy selection
    Prioritizes most significant digit changes
    Practical Use:
    1. RPG game mechanics for optimal skill point allocation to get biggest combat advantage
    2. Financial portfolio rebalancing to maximize digit-based security codes (a bank might rebalance account numbers from 371429 to 399999 when detecting fraud patterns, for example)
    3. Inventory management systems optimizing product combos assembling (a retailer could combine items priced at $47, $58, $63 into $99 "deal packages")
    
## 5. beautiful_digits.cpp
Counts numbers with all identical digits between given bounds.
Details:

    Generates numbers mathematically rather than checking each
    Handles large ranges efficiently
    Practical Use:
    1. Excluding "beautiful" numbers when lottery winning numbers creation to prevent fraud, encourage randomness and reduce cases where suspiciosly perfect numbers win
    2. Reject user-chosen PINs or passwords with identical digits forcing customers to use more complex combinations
    3. Prevents human reading errors caused by misreading repeated digits in aircraft component serial numbers, which could lead to fatal replacement mistakes during maintenance

## 6. odd_and_even_in_sequence.cpp
Finds mismatched odd/even positions in a sequence and identifies if the sequence can be fixed by swapping two elements just once.
Details:

    Checks element parity against index parity
    Finds at most two mismatched positions
    Practical Use:
    1. Validating barcode/QR code parity patterns
    2. Checking alternating shift schedules (day/night rotations)
    3. Verifying proper sequencing in manufacturing assembly lines
    
## 7. secret_santa.cpp
Validates and corrects Secret Santa gift assignments to ensure a single cycle where everyone gives/receives exactly one gift. Corrects invalid assignments by reassigning gifts when possible.
Details:

    Uses graph cycle detection to validate assignments
    Implements reassignment logic when someone gets two gifts or no gift
    Practical Use:
    1. Classroom assignment systems ensuring each student both tutors and gets tutored
    2. Shift scheduling where coworkers cover for each other in rotation
    3. Rotating oversight responsibilities among departments to prevent self-review and create mandatory cross-departmental verification chains

## 8. conference_room.cpp
Performs geometric transformations to align virtual space coordinates with physical room dimensions.
Details:

    Uses trigonometric transformations
    Handles scaling and rotation
    Practical Use:
    1. Digital twin implementations for smart office or smart home systems
    2. Hybrid Zoom/VR meetings with proper speaker placement relative to real room acoustics and correct avatar spacing to match physical distancing
    3. AR furniture placement apps ensuring proper scaling while virtual shopping at IKEA
    
## 9. free_lunch.cpp
Uses dynamic programming to find optimal coupon usage sequence for minimal spending over multiple days.
Details:

    2D DP table tracking cost and coupons
    Backtracks to find coupon usage days
    Practical Use:
    1. Meal plan optimization for budget-conscious families
    2. RPG character development with limited upgrade resources (when to use limited "doubleXP" coupon across multiple training sessions; upgrade permanent stat boots vs temporary buffs)
    3. Corporate cafeteria coupon allocation systems (a company tweaks the algorithm to ensure a) no employee gets >1 coupon/week; b) coupons distribute equally across departments)
    
## 10. polygonal_pie.cpp
Calculates a vertical line position that splits a polygon into two regions of equal area using binary search and shoelace formula.
Details:

    Implements Gauss's shoelace formula for area calculation
    Uses binary search to find the optimal dividing line
    Practical Use:
    1. Agricultural land fair division for inheritance or partnership dissolution
    2. Urban planning when splitting park areas or zoning districts
    3. CAD software for designing balanced mechanical parts
    
