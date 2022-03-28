/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:48:08 by akotzky           #+#    #+#             */
/*   Updated: 2022/03/28 16:36:49 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP
# define __STACK_HPP

# include "vector.hpp"

namespace ft {

    template<typename T, class Sequence = ft::vector<T> >
    class stack
    {
        private:

            typedef typename Sequence::value_type sequence_value_type;

            template<typename Tp, typename Seq>
            friend bool
            operator==(stack<Tp, Seq> const&, stack<Tp, Seq> const&);

            template<typename Tp, typename Seq>
            friend bool
            operator<(stack<Tp, Seq> const&, stack<Tp, Seq> const&);

        protected:

            Sequence c;
        
        public:

            typedef typename Sequence::value_type           value_type;
            typedef typename Sequence::reference            reference;
            typedef typename Sequence::const_reference      const_reference;
            typedef typename Sequence::size_type            size_type;
            typedef          Sequence                       container_type;

            explicit
            stack(container_type const& cntr = container_type())
            : c(cntr)
            {}

            bool
            empty() const {
                return (c.empty());
            }

            size_type
            size() const {
                return (c.size());
            }

            value_type&
            top() {
                return (c.back());
            }

            const value_type&
            top() const {
                return (c.back());
            }

            void
            push(value_type const& val) {
                c.push_back(val);
            }

            void
            pop() {
                c.pop_back();
            }
    };

    template<typename T, typename Seq>
    inline bool
    operator==(stack<T, Seq> const& x, stack<T, Seq> const& y) {
        return (x.c == y.c);
    }

    template<typename T, typename Seq>
    inline bool
    operator<(stack<T, Seq> const& x, stack<T, Seq> const& y) {
        return (x.c < y.c);
    }

    template<typename T, typename Seq>
    inline bool
    operator!=(stack<T, Seq> const& x, stack<T, Seq> const& y) {
        return (!(x == y));
    }

    template<typename T, typename Seq>
    inline bool
    operator>(stack<T, Seq> const& x, stack<T, Seq> const& y) {
        return (y < x);
    }

    template<typename T, typename Seq>
    inline bool
    operator<=(stack<T, Seq> const& x, stack<T, Seq> const& y) {
        return (!(y < x));
    }

    template<typename T, typename Seq>
    inline bool
    operator>=(stack<T, Seq> const& x, stack<T, Seq> const& y) {
        return (!(x < y));
    }
};
#endif