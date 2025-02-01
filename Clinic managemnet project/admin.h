#ifndef _ADMIN_H_
#define _ADMIN_H_

#include <stdio.h>
#include <stdlib.h>

typedef enum Pass_t
{
    InvalidPAss,
    ValiPass

} PASS;
typedef enum ID_t
{
    IDNotExist,
    IDExist
} ID;
typedef enum ADD_t
{
    ADDED,
    NOTADDED,
    TOOMANYTrails
} ADD;
typedef enum EDIT_t
{
    EDITTED,
    NOTEDITTED,
    E_TOOMANYTrails
} EDIT;
typedef struct Patient_t
{
    char Name[12];
    int Age;
    char Gender;
    int ID;
    struct Patient_t *Next;
    struct Patient_t *Prev;

} Patient;

typedef struct Reservation_t
{
    char Name[12];
    int Age;
    char Gender;
    int ID;
    struct Reservation_t *Next;
    struct Reservation_t *Prev;

} Reserve;

typedef enum ISRESERVED_t
{
    RESERVED,
    NOTRESERVED
} ISRESERVED;

typedef enum ISCANCELLED_t
{
    CANCELLED,
    NOTCANCELLED
} ISCANCELLED;

PASS Check_pass();
ADD Add_Patient();
ID ID_CHECK(int ID);
EDIT Edit_Patient(Patient *Head_OF_Patient);
ISRESERVED Reserve_Slot();
ISCANCELLED Cancel_Reservation();

#endif