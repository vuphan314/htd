/*
 * File:   AddIdenticalJoinNodeParentOperation.hpp
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

#ifndef HTD_HTD_ADDIDENTICALJOINNODEPARENTOPERATION_HPP
#define	HTD_HTD_ADDIDENTICALJOINNODEPARENTOPERATION_HPP

#include <htd/Globals.hpp>
#include <htd/ITreeDecompositionManipulationOperation.hpp>

namespace htd
{
    /**
     *  Implementation of a manipulation operation which ensures that the parents of join nodes of a decomposition have the same bag content as the join nodes.
     */
    class AddIdenticalJoinNodeParentOperation : public virtual htd::ITreeDecompositionManipulationOperation
    {
        public:
            /**
             *  Constructor for a new manipulation operation of type AddIdenticalJoinNodeParentOperation.
             *
             *  @param[in] enforceAdditionalNode    Set this option to true to enforce a new parent node for join
             *  nodes also in those cases where the bag contents of the join node and its old parent did already
             *  match. If this option is set to false, no action will be triggered for join nodes for which the
             *  nodes' bag content already matches the parent's bag content.
             */
            AddIdenticalJoinNodeParentOperation(bool enforceAdditionalNode = true);

            ~AddIdenticalJoinNodeParentOperation();

            void apply(htd::IMutableTreeDecomposition & decomposition) const HTD_OVERRIDE;

            void apply(htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::vertex_t> & relevantVertices, std::vector<htd::vertex_t> & createdVertices, std::vector<htd::vertex_t> & removedVertices) const HTD_OVERRIDE;

            void apply(htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const HTD_OVERRIDE;

            void apply(htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::vertex_t> & relevantVertices, const std::vector<htd::ILabelingFunction *> & labelingFunctions, std::vector<htd::vertex_t> & createdVertices, std::vector<htd::vertex_t> & removedVertices) const HTD_OVERRIDE;

            bool isLocalOperation(void) const HTD_OVERRIDE;

            bool createsTreeNodes(void) const HTD_OVERRIDE;

            bool removesTreeNodes(void) const HTD_OVERRIDE;

            bool modifiesBagContents(void) const HTD_OVERRIDE;

            bool createsSubsetMaximalBags(void) const HTD_OVERRIDE;

            bool createsLocationDependendLabels(void) const HTD_OVERRIDE;

            AddIdenticalJoinNodeParentOperation * clone(void) const HTD_OVERRIDE;

        private:
            bool enforceAdditionalNode_;
    };
}

#endif /* HTD_HTD_ADDIDENTICALJOINNODEPARENTOPERATION_HPP */
