namespace std _GLIBCXX_VISIBILITY(default)
{

  /**
   *  @addtogroup utilities
   *  @{
   */


  template<class _T1, class _T2>
    struct pair
    {
      typedef _T1 first_type;
      typedef _T2 second_type;

      _T1 first;
      _T2 second;

//constexpr
      pair()
      : first(), second() { }
//constexpr
      pair(const _T1& __a, const _T2& __b)
      : first(__a), second(__b) { }

      /** There is also a templated copy ctor for the @c pair class itself.  */
    template<class _U1, class _U2, class = typename enable_if<__and_<is_convertible<const _U1&, _T1>, is_convertible<const _U2&, _T2>>::value>::type>
    constexpr pair(const pair<_U1, _U2>& __p)
    : first(__p.first), second(__p.second) { }

    constexpr pair(const pair&) = default;
    constexpr pair(pair&&) = default;

    // DR 811.
    template<class _U1, class = typename enable_if<is_convertible<_U1, _T1>::value>::type>
    constexpr pair(_U1&& __x, const _T2& __y)
    : first(std::forward<_U1>(__x)), second(__y) { }

    template<class _U2, class = typename enable_if<is_convertible<_U2, _T2>::value>::type>
    constexpr pair(const _T1& __x, _U2&& __y)
    : first(__x), second(std::forward<_U2>(__y)) { }

    template<class _U1, class _U2, class = typename enable_if<__and_<is_convertible<_U1, _T1>, is_convertible<_U2, _T2>>::value>::type>
    constexpr pair(_U1&& __x, _U2&& __y)
    : first(std::forward<_U1>(__x)), second(std::forward<_U2>(__y)) { }

    template<class _U1, class _U2, class = typename enable_if<__and_<is_convertible<_U1, _T1>, is_convertible<_U2, _T2>>::value>::type>
    constexpr pair(pair<_U1, _U2>&& __p)
    : first(std::forward<_U1>(__p.first)),
      second(std::forward<_U2>(__p.second)) { }

    template<typename... _Args1, typename... _Args2>
    pair(piecewise_construct_t, tuple<_Args1...>, tuple<_Args2...>);

    pair&
    operator=(const pair& __p) {
        first = __p.first;
        second = __p.second;
        return *this;
    }

    pair&
    operator=(pair&& __p)
    noexcept(__and_<is_nothrow_move_assignable<_T1>, is_nothrow_move_assignable<_T2>>::value) {
        first = std::forward<first_type>(__p.first);
        second = std::forward<second_type>(__p.second);
        return *this;
    }

    template<class _U1, class _U2>
    pair&
    operator=(const pair<_U1, _U2>& __p) {
      first = __p.first;
      second = __p.second;
      return *this;
    }

    template<class _U1, class _U2>
    pair&
    operator=(pair<_U1, _U2>&& __p) {
      first = std::forward<_U1>(__p.first);
      second = std::forward<_U2>(__p.second);
      return *this;
    }

    void
    swap(pair& __p)
    noexcept(noexcept(swap(first, __p.first)) && noexcept(swap(second, __p.second)))
    {
        using std::swap;
        swap(first, __p.first);
        swap(second, __p.second);
    }

    private:
    template< typename... _Args1, std::size_t... _Indexes1,
              typename... _Args2, std::size_t... _Indexes2>
    pair(tuple<_Args1...>&, tuple<_Args2...>&, _Index_tuple<_Indexes1...>, _Index_tuple<_Indexes2...>);
    };

  /// Two pairs of the same type are equal iff their members are equal.
  template<class _T1, class _T2>
    inline _GLIBCXX_CONSTEXPR bool
    operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __x.first == __y.first && __x.second == __y.second; }

  /// <http://gcc.gnu.org/onlinedocs/libstdc++/manual/utilities.html>
  template<class _T1, class _T2>
    inline _GLIBCXX_CONSTEXPR bool
    operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __x.first < __y.first
         || (!(__y.first < __x.first) && __x.second < __y.second); }

  /// Uses @c operator== to find the result.
  template<class _T1, class _T2>
    inline _GLIBCXX_CONSTEXPR bool
    operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__x == __y); }

  /// Uses @c operator< to find the result.
  template<class _T1, class _T2>
    inline _GLIBCXX_CONSTEXPR bool
    operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __y < __x; }

  /// Uses @c operator< to find the result.
  template<class _T1, class _T2>
    inline _GLIBCXX_CONSTEXPR bool
    operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__y < __x); }

  /// Uses @c operator< to find the result.
  template<class _T1, class _T2>
    inline _GLIBCXX_CONSTEXPR bool
    operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__x < __y); }


  /**
   *  @brief A convenience wrapper for creating a pair from two objects.
   *  @param  __x  The first object.
   *  @param  __y  The second object.
   *  @return   A newly-constructed pair<> object of the appropriate type.
   *
   *  The standard requires that the objects be passed by reference-to-const,
   *  but LWG issue #181 says they should be passed by const value.  We follow
   *  the LWG by default.
   */
  // _GLIBCXX_RESOLVE_LIB_DEFECTS
  // 181.  make_pair() unintended behavior

  template<class _T1, class _T2>
    inline pair<_T1, _T2>
    make_pair(_T1 __x, _T2 __y)
    { return pair<_T1, _T2>(__x, __y); }

  /// @}

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std
