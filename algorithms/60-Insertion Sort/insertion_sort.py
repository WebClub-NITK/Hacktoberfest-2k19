import copy

def insertion_sort(unsorted_input):
    # To not change the input-array, copy it
    sorted = copy.copy(unsorted_input)

    # Iterate over the the whole given array
    for index, valueToBeSorted in enumerate(sorted):
        # The array 'sorted' is parted into two sections: the first 'index' fields are already sorted and the rest is unsorted.
        # Each round we sort the next value in the unsorted section ('valueToBeSorted', at index 'index') into the sorted section.
        inspectedIndex = index
        # As long as the value left to the currently inspected index is larger than the value we want to sort into the list, shift the values to the right
        while inspectedIndex > 0 and sorted[inspectedIndex - 1] > valueToBeSorted:
            sorted[inspectedIndex] = sorted[inspectedIndex - 1]
            inspectedIndex -= 1
        # Everything that is larger than the value we want to sort is to the right of the inspected index, so we can insert the value at this point
        sorted[inspectedIndex] = valueToBeSorted
    return sorted
