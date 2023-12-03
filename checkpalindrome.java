
// // check if the sum of digit pf N is palindrome
// // I/P-92 (SUM=9+2=11)
// // O/P-YES
// import java.util.*;

// class check {
// public static void main(String[] args) {

// }
// }
// // Online C++ compiler to run C++ program online

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// int num = 56;
// int sum = 0;

// while (num != 0) {
// int temp = (num % 10);
// sum = sum + temp;
// num /= 10;
// }

// // Driver Code

// // convert sum to string
// string str = to_string(sum);

// // reverse the string
// string string_rev = "" + str;
// reverse(string_rev.begin(), string_rev.end());

// // check the palindrome
// cout << ((str == string_rev) ? "Yes" : "No");
// }
// #include<iostream>
// using namespace std;

// /*C++ Function to print leaders in an array */
// void printLeaders(int arr[], int size)
// {
// for (int i = 0; i < size; i++)
// {
// int j;
// for (j = i+1; j < size; j++)
// {
// if (arr[i] <=arr[j])
// break;
// }
// if (j == size) // the loop didn't break
// cout << arr[i] << " ";
// }
// }

// /* Driver program to test above function */
// int main()
// {
// int arr[] = {16, 17, 4, 3, 5, 2};
// int n = sizeof(arr)/sizeof(arr[0]);
// printLeaders(arr, n);
// return 0;
// }
