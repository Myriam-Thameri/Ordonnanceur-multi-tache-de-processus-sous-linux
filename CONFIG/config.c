#include "./types.h"

CONFIG config = {
    .process_count = 7,
    .processes = {
        {
            .ID = "P01",
            .arrival_time = 0,
            .execution_time = 10,
            .priority = 3,
            .io_count = 2,
            .io_operations = {
                { 
                    .start_time = 2, 
                    .duration = 3 
                },
                { 
                    .start_time = 6, 
                    .duration = 5 
                }
            }
        },
        {
            .ID = "P02",
            .arrival_time = 2,
            .execution_time = 6,
            .priority = 1,
            .io_count = 1,
            .io_operations = {
                { 
                    .start_time = 3, 
                    .duration = 4 
                }
            }
        },
        {
            .ID = "P03",
            .arrival_time = 3,
            .execution_time = 6,
            .priority = 3,
            .io_count = 0
        },
        {
            .ID = "P04",
            .arrival_time = 5,
            .execution_time = 4,
            .priority = 2,
            .io_count = 0
        },
        {
            .ID = "P05",
            .arrival_time = 8,
            .execution_time = 8,
            .priority = 4,
            .io_count = 3,
            .io_operations = {
                { 
                    .start_time = 2, 
                    .duration = 2 
                },
                { 
                    .start_time = 4, 
                    .duration = 2 
                },
                { 
                    .start_time = 6, 
                    .duration = 2 
                }
            }
        },
        {
            .ID = "P06",
            .arrival_time = 8,
            .execution_time = 8,
            .priority = 1,
            .io_count = 0
        },
        {
            .ID = "P07",
            .arrival_time = 3,
            .execution_time = 8,
            .priority = 4,
            .io_count = 1,
            .io_operations = {
                { 
                    .start_time = 1, 
                    .duration = 2 
                }
            }
        }
    }
};