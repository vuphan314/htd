/*
 * File:   LimitMaximumIntroducedVertexCountOperation.hpp
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

#ifndef HTD_HTD_LIMITMAXIMUMINTRODUCEDVERTEXCOUNTOPERATION_HPP
#define	HTD_HTD_LIMITMAXIMUMINTRODUCEDVERTEXCOUNTOPERATION_HPP

#include <htd/Globals.hpp>
#include <htd/IMutableTreeDecomposition.hpp>
#include <htd/IPathDecompositionManipulationOperation.hpp>
#include <htd/ITreeDecompositionManipulationOperation.hpp>

namespace htd
{
    class LimitMaximumIntroducedVertexCountOperation : public virtual htd::IPathDecompositionManipulationOperation, public virtual htd::ITreeDecompositionManipulationOperation
    {
        public:
            /**
             *  Constructor for a new manipulation operation of type LimitMaximumIntroducedVertexCountOperation.
             *
             *  @param[in] limit    The maximum number of introduced vertices for a decomposition node.
             *
             *  @note Leaf nodes are not treated as introduce nodes by default, i.e. the provided limit does not apply to leaf nodes.
             */
            LimitMaximumIntroducedVertexCountOperation(std::size_t limit);

            /**
             *  Constructor for a new manipulation operation of type LimitMaximumIntroducedVertexCountOperation.
             *
             *  @param[in] limit                            The maximum number of introduced vertices for a decomposition node.
             *  @param[in] treatLeafNodesAsIntroduceNodes   A boolean flag whether leaf nodes shall be treated as introduce nodes in the context of this operation.
             */
            LimitMaximumIntroducedVertexCountOperation(std::size_t limit, bool treatLeafNodesAsIntroduceNodes);

            ~LimitMaximumIntroducedVertexCountOperation();

            void apply(htd::IMutablePathDecomposition & decomposition) const HTD_OVERRIDE;

            void apply(htd::IMutablePathDecomposition & decomposition, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const HTD_OVERRIDE;

            void apply(htd::IMutableTreeDecomposition & decomposition) const HTD_OVERRIDE;

            void apply(htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const HTD_OVERRIDE;

            LimitMaximumIntroducedVertexCountOperation * clone(void) const HTD_OVERRIDE;

        private:
            std::size_t limit_;

            bool treatLeafNodesAsIntroduceNodes_;
    };
}

#endif /* HTD_HTD_LIMITMAXIMUMINTRODUCEDVERTEXCOUNTOPERATION_HPP */
