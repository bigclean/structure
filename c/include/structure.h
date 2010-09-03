/* strucol.h --- 
 * 
 * Filename: strucol.h
 * Description: general types defintion
 * Author: bigclean <potteryzero at gmail dot com>
 * Created: Wed Aug 25 15:43
 * Last-Updated: Wed Aug 25 15:43
 */

/* Code: */

/**
 * @file structure.h
 * @brief general types for this project
 * @date Aug 19, 2010
 */

#ifndef __STRUCTURE_H_
#define __STRUCTURE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef int elem_type;

/*
 * XXX: see stdbool.h(Gcc), maybe should use macro to include it when
 *      compiled by GCC
 */
enum bool {
        FALSE = 0,
        TRUE = 1
};
typedef enum bool Bool; /*  general boolean type */

/**
 * @note To be compatible with 'Status' definition in P10 of textbook
 */
enum Status_t {
        OVERFLOW = -2,
        INFEASIBILE = -1,
        ERROR = 0,
        SUCCESS = 1
};
typedef enum Status_t Status;

#ifdef __cplusplus
}
#endif

#endif

/* strucol.h ends here */
