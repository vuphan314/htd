/*
 * File:   SemiNormalizationOperation.hpp
 *
 * Author: ABSEHER Michael (abseher@dbai.tuwien.ac.at)
 * 
 * Copyright 2015-2016, Michael Abseher
 *    E-Mail: <abseher@dbai.tuwien.ac.at>
 * 
 * This file is part of htd.
 * 
 * htd is free software: you can redistribute it and/or modify it under 
 * the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * htd is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public 
 * License for more details.

 * You should have received a copy of the GNU General Public License
 * along with htd.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HTD_HTD_SEMINORMALIZATIONOPERATION_HPP
#define	HTD_HTD_SEMINORMALIZATIONOPERATION_HPP

#include <htd/Globals.hpp>
#include <htd/WeakNormalizationOperation.hpp>
#include <htd/ITreeDecompositionManipulationOperation.hpp>

namespace htd
{
    class SemiNormalizationOperation : public htd::WeakNormalizationOperation
    {
        public:
            /**
             *  Constructor for a new manipulation operation of type SemiNormalizationOperation.
             */
            SemiNormalizationOperation(void);

            /**
             *  Constructor for a new manipulation operation of type SemiNormalizationOperation.
             *
             *  @param[in] emptyRoot                A boolean flag whether the decomposition shall have a root node with empty bag.
             *  @param[in] emptyLeaves              A boolean flag whether the decomposition's leave nodes shall have an empty bag.
             *  @param[in] identicalJoinNodeParent  A boolean flag whether each join node shall have a parent with equal bag content.
             */
            SemiNormalizationOperation(bool emptyRoot, bool emptyLeaves, bool identicalJoinNodeParent);

            virtual ~SemiNormalizationOperation();

            void apply(htd::IMutablePathDecomposition & decomposition) const HTD_OVERRIDE;

            void apply(htd::IMutablePathDecomposition & decomposition, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const HTD_OVERRIDE;

            void apply(htd::IMutableTreeDecomposition & decomposition) const HTD_OVERRIDE;

            void apply(htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const HTD_OVERRIDE;

            SemiNormalizationOperation * clone(void) const HTD_OVERRIDE;
    };
}

#endif /* HTD_HTD_SEMINORMALIZATIONOPERATION_HPP */
