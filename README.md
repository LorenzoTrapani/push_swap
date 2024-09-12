# Introduction

The Push_swap project is part of the 42 curriculum. It involves sorting a stack of numbers using a limited set of operations. The goal is to write a program that generates the smallest number of moves to sort a given stack, optimizing both algorithmic efficiency and implementation.

# Objectives

The main objective of the project is to implement efficient sorting algorithms using stacks, applying specific operations to achieve the desired result. You’ll be expected to explore algorithmic approaches and optimize the sorting process to reduce the number of operations.
# Problem Overview

You are given two stacks: a (which contains a set of unsorted numbers) and b (initially empty). Your task is to sort the numbers in stack a using the fewest number of moves, using specific operations to manipulate the stacks.

Allowed Operations:

  - sa: Swap the first two elements at the top of stack a.
  - sb: Swap the first two elements at the top of stack b.
  - ss: Swap the first two elements at the top of both a and b.
  - pa: Push the top element from stack b onto stack a.
  - pb: Push the top element from stack a onto stack b.
  - ra: Rotate stack a upwards (the top element becomes the last).
  - rb: Rotate stack b upwards.
  - rr: Rotate both stacks a and b upwards.
  - rra: Reverse rotate stack a (the last element becomes the first).
  - rrb: Reverse rotate stack b.
  - rrr: Reverse rotate both stacks a and b.
