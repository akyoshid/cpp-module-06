/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:34:25 by akyoshid          #+#    #+#             */
/*   Updated: 2025/09/04 14:41:44 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_BASE_HPP_
# define EX02_BASE_HPP_

class Base {
 public:
    virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
