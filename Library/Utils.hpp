#pragma once
#include <type_traits>
#include <algorithm>

template <typename T>
struct is_regular : std::integral_constant<bool, 
	std::is_default_constructible<T>::value && 
	std::is_copy_constructible<T>::value &&
	std::is_move_constructible<T>::value &&
	std::is_copy_assignable<T>::value &&
	std::is_move_assignable<T>::value>
{};

template <typename ForwardIterator>
void InsertionSort(ForwardIterator first, ForwardIterator last) {
	for (auto i = first; i != last; ++i)
		std::rotate(std::upper_bound(first, i, *i), i, std::next(i));
}

template <typename ForwardIterator, typename Compare = std::less<>>
void QuickSort(ForwardIterator first, ForwardIterator last, Compare cmp = Compare{}) {
	auto const N = std::distance(first, last);
	if (N <= 1) return;
	auto const pivot = std::next(first, N / 2);
	std::nth_element(first, pivot, last, cmp);
	QuickSort(first, pivot, cmp);
	QuickSort(pivot, last, cmp);
}