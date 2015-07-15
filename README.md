# c64 FDD For Fun

## Introduction

C64 FDD For Fun

## The project
1. Schematics
2. Firmware
3. Information.
4. Serial Bus information
5. C64 IEC DIN-6 Female connector

### C64 Serial Bus Information


#### Serial Bus Pinouts


     Pin | Name    | Description               
    -----|---------|---------------------------
     1   | SRQ     | Serial Service Request In 
     2   | GND     | Ground                    
     3   | ATN     | Serial Attention In/Out   
     4   | CLK     | Serial Clock In/Out       
     5   | DATA    | Serial Data In/Out        
     6   | RESET   | Serial Reset              

    All signals are active low.


  SRQ: Serial Service Request In

 This signal is not used on the C64. On C128 it is replaced with Fast Serial
 Clock for the 1571 disk drive.


  ATN: Serial Attention In/Out

 Sending any byte with the ATN line low (sending under attention) causes it
 to be interpreted as a Bus Command for peripherals on the serial bus.

 When the C64 brings this signal LOW, all other devices start listening for
 it to transmit an address. The device addressed must respond in a preset
 period of time; otherwise, the C64 will assume that the device addressed is
 not on the bus, and will return an error in the STATUS word.

 Usually, the address byte will be followed by one to two commands for the
 device addressed, meaning the secondary address and channel on the peripheral.
 Such a command can be one of the following:

```
    20
    40
    60
    E0
    F0
```

 
  CLK: Serial Clock In/Out

  This signal is for timing the data sent on the serial bus. This signal is
  always generated by the active TALKER. RISING EDGE OF THE CLOCK means data
  bit is valid.


  DATA: Serial Data In/Out

  Data on the serial bus is transmitted bit by bit at a time on this line.


  RESET: Serial Reset

  You may disconnect this line to save your disk drive. The easiest way is to
  do that on the cable, thus avoiding any modifications on your peripherals.



#### Serial Bus Timing


```
 ___
 CLK    |____|~~~~| Ts Bit Set-up time
    : Ts : Tv : Tv Bit Valid time



     |<--------- Byte sent under attention (to devices) ------------>|

 ___    ____                                                        _____ _____
 ATN       |________________________________________________________|
       :                                :
 ___    ______     ________ ___ ___ ___ ___ ___ ___ ___ ___         :
 CLK       : |_____|      |_| |_| |_| |_| |_| |_| |_| |_| |______________ _____
       :       :        :                 :         :
       : Tat : :Th: Tne :                             : Tf : Tr :
 ____   ________ : :  :___________________________________:____:
 DATA   ___|\\\\\__:__|    |__||__||__||__||__||__||__||__|    |_________ _____
                  :     0   1   2   3   4   5   6   7      :
                  :    LSB                         MSB     :
              :     :                      :
              :     : Data Valid      Listener: Data Accepted
              : Listener READY-FOR-DATA

```



        END-OR-IDENTIFY HANDSHAKE (LAST BYTE IN MESSAGE)
```
 ___    _______________________________________________________________________
 ATN
 ___     ___ ___      ________________ ___ ___ ___ ___ ___ ___ ___ ___       __
 CLK    _| |_| |______|              |_| |_| |_| |_| |_| |_| |_| |_| |_______|_
           :      :          :                               :       :
           :Tf:Tbb:Th:Tye:Tei:Try:                               :Tf :Tfr:
 ____   __________:   :  :___:   :_______________________________________:   :_
 DATA   |__||__|  |______|   |___|   :                                   |___|_
     6   7        :  :   :   :   :                   :
        MSB       :  :   :   :   : Talker Sending            :
              :  :   :   : Listener READY-FOR-DATA      System
              :  :   : EOI-Timeout Handshake          Line Release
              :  : Listener READY-FOR-DATA
              : Talker Ready-To-Send
```




        TALK-ATTENTION TURN AROUND (TALKER AND LISTENER REVERSED)
```
 ___                 _________________________________________________________
 ATN    _____________|
             :
 ___     ___ ___     :   _____   ________ ___ ___ ___ ___ ___ ___ ___ ___
 CLK    _| |_| |_________|   |___|      |_| |_| |_| |_| |_| |_| |_| |_| |_____
           :     :   :   :   :      :                               :
           :Tf:Tr:Ttk:Tdc:Tda:Th:Try:                               :Tf :
 ____   __________:  :       :   :  :_______________________________________:
 DATA   |__||__|  |_________________|   :|__||__||__||__||__||__||__||__|   |_
     6   7       :   :   :   :  :   : 0   1   2   3   4   5   6   7
        MSB      :   :   :   :  :   :LSB                         MSB
             :   :   :   :  :   :
             :   :   :   :  :   : Data Valid
             :   :   :   :  : Listener READY-FOR-DATA
             :   :   :   : Talker Ready-To-Send
             :   :   : Device acknowledges it's now TALKER.
             :   : Becomes LISTENER, Clock = High, Data = Low
             : Talker Ready-To-Send
```


```
 ___    _____________________________________________________________________
 ATN
 ___        _________ ___ ___ ___ ___ ___ ___ ___ ___       ________ ___ ___
 CLK    ____|       |_| |_| |_| |_| |_| |_| |_| |_| |_______|      |_| |_| |_
        :       :                   :       :      :
        :Th :Tne:                               :Tf :Tbb:Th:Tne:
 ____       :   :___:___________________________________:      :_____________
 DATA   ________|   :|__||__||__||__||__||__||__||__|   |______|
        :   :   : 0   1   2   3   4   5   6   7     :
        :   :   :LSB                         MSB    :
        :   :   :                   :
        :   :   : TALKER SENDING        Listener: Data Accepted
        :   : LISTENER READY-FOR-DATA
        : TALKER READY-TO-SEND
```



#### Serial Bus Timing


     Description                | Symbol   | Min     | Typ     | Max 
    ----------------------------|----------|---------|---------|----
    ATN Response (required) 1)  |   Tat    |  -      |    -    |   1000us
    Listener Hold-Off           |   Th     |  0      |    -    |   oo
    Non-EOI Response to RFD 2)  |   Tne    |  -      |    40us |   200us
    Bit Set-Up Talker  4)       |   Ts     | 20us    |    70us |    -
    Data Valid                  |   Tv     | 20us    |    20us |    -
    Frame Handshake  3)         |   Tf     | 0       |    20   |   1000us
    Frame to Release of ATN     |   Tr     | 20us    |    -    |   -
    Between Bytes Time          |   Tbb    | 100us   |    -    |   -
    EOI Response Time           |   Tye    | 200us   |    250us|   -
    EOI Response Hold Time  5)  |   Tei    | 60us    |    -    |   -
    Talker Response Limit       |   Try    | 0       |    30us |   60us
    Byte-Acknowledge  4)        |   Tpr    | 20us    |    30us |   -
    Talk-Attention Release      |   Ttk    | 20us    |    30us |   100us
    Talk-Attention Acknowledge  |   Tdc    | 0       |    -    |   -
    Talk-Attention Ack. Hold    |   Tda    | 80us    |    -    |   -
    EOI Acknowledge             |   Tfr    | 60us    |    -    |   -


#### Notes
1.  If maximum time exceeded, device not present error.
2.  If maximum time exceeded, EOI response required.
3.  If maximum time exceeded, frame error.
4.  Tv and Tpr minimum must be 60us for external device to be a talker.
5.  Tei minimum must be 80us for external device to be a listener.

### 5. Female DIN-6 IEC connection

```
    Rear view of the C64 connector (female connector)

  < BROWN >       _____     < YELLOW > 
    (DATA) ----- /       \ ---- SRQ
               / O     O \
              |           |
         N/C--|---> O     |
              |           |
 CLK      -----\ O     O / ----   GND 
< BLACK >       \___O___/      < BROWN >
                    |
                  ATN (2nd test PIN on the left)
                < BLUE >
```
