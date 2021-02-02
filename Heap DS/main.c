#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include "appconst.h"
#include "heap.h"

void test_sort (int32_t data[],uint32_t len){
    uint32_t idx;
    for (idx = 1; idx < len; ++idx){
        //printf("%d\t",data[idx]);
        assert(data[idx] <= data[idx+1]);
    }
}

void test_heap(){

    int32_t data[] = { 0, 23, 54, 7, 19, 87, 56, 93, 61, 17, 73};
    Heap heap = heap_new(data, 10);
    heap_insert(&heap, 47);
    assert(heap_size(&heap) == 11);
    heap_test(&heap);
    assert(heap_get_max(&heap) == 93);
    assert(heap_extract_max(&heap) == 93);
    heap_test(&heap);
    assert(heap_size(&heap) == 10);

    heap_sort(&heap);
    test_sort(heap.data, 10);
}


int main()
{
    //printf("Hello world!\n");
    test_heap();
    return 0;
}
