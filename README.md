# 1. Introduction

## 1.1 Scope of document
This document describes a program to check if a path exists in an unsigned integer vector, according to the rule :
* Traversing rules:
    * The first index is 0, that’s where the algorithm starts.
    * Algorithm may only ‘jump’ forward or backwards in the array according to the value in the ‘current’ element (e.g. if the value at index 0 is 3 the algo may only advance to index 3. if the value at index 3 is 2 – the algo may advance to both index 5 and index 1).
