# This program is made to calculate athan prayer time.

## How to compile ?

#### 1. To run unit_test:

```bash
$ make unit_test
$ ./athan
..
```

#### 2. To compile as a static library. It will generate "athan.a" file.

```bash
$ make 
..
```

## Public APIs

   API            | Return           | Argument         | Function
                  |                  |                  |
Set_Offset        |  -               | float            | Set Athan prayer time offset value
Get_Offset        |  float           | -                | Get Athan prayer time offset value 
Set_Latitude      |  -               | double           | Set latitude value
Get_Latitude      |  double          | -                | Get latitude value
Set_Longitude     |  -               | double           | Set longitude value
Get_Longitude     |  double          | -                | Get longitude value
Get_Athan_Time    |  ST_ATHAN_TIME   | EN_ATHAN_TIME    | Get Athan time
 
 
## How to use ?

1. This class is built using the singleton method.
2. At first user has to set the offest value by using Set_Offset API.
3. Then, user has to set latitude and longitude by using Set_Latitude and Set_Longitude API respectively.
4. After setting has done, user can retrieve prayer time for each prayer time by using Get_Athan_Time with the available athan enumeration.

   For example :
   
   Athan::GetInstance()->Get_Athan_Time(EN_ATHAN_TIME_SUBUH)

5. Calling this API will return value based on ST_ATHAN_TIME structure with contain the value of hour, minute and second.
   User can get the value directly by accessing the member variables (hour, min, sec).
   
* For more details, please refer to unit test in CPP file.



