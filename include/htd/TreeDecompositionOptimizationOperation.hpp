/*
 * File:   TreeDecompositionOptimizationOperation.hpp
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

#ifndef HTD_HTD_TREEDECOMPOSITIONOPTIMIZATIONOPERATION_HPP
#define	HTD_HTD_TREEDECOMPOSITIONOPTIMIZATIONOPERATION_HPP

#include <htd/Globals.hpp>
#include <htd/ITreeDecompositionManipulationOperation.hpp>
#include <htd/ITreeDecompositionFitnessFunction.hpp>
#include <htd/ITreeDecompositionManipulationOperation.hpp>
#include <htd/IVertexSelectionStrategy.hpp>

#include <vector>

namespace htd
{
    /**
     *  Implementation of the IDecompositionManipulationOperation interface which manipulates
     *  given tree decompositions in such a way that the fitness value of the resulting tree 
     *  decomposition is maximal.
     */
    class TreeDecompositionOptimizationOperation : public virtual htd::ITreeDecompositionManipulationOperation
    {
        public:
            /**
             *  Constructor for a new manipulation operation of type TreeDecompositionOptimizationOperation.
             *
             *  @note This constructor creates an optimization operation which actually does not perform any optimization tasks
             *  due to the lack of a fitness function. That is, applying the constructed operation to a decomposition will only
             *  apply the desired manipulation operations and add requested labels.
             */
            TreeDecompositionOptimizationOperation(void);

            /**
             *  Constructor for a new manipulation operation of type TreeDecompositionOptimizationOperation.
             *
             *  @param[in] fitnessFunction  The fitness function which is used to determine the quality of tree decompositions.
             */
            TreeDecompositionOptimizationOperation(const htd::ITreeDecompositionFitnessFunction & fitnessFunction);

            /**
             *  Constructor for a new manipulation operation of type TreeDecompositionOptimizationOperation.
             *
             *  @param[in] fitnessFunction          The fitness function which is used to determine the quality of tree decompositions.
             *  @param[in] enforceNaiveOptimization Enforce that each iteration of the optimization algorithm starts from scratch with a copy of the given decomposition.
             */
            TreeDecompositionOptimizationOperation(const htd::ITreeDecompositionFitnessFunction & fitnessFunction, bool enforceNaiveOptimization);

            ~TreeDecompositionOptimizationOperation();

            void apply(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition) const HTD_OVERRIDE;

            void apply(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::vertex_t> & relevantVertices, std::vector<htd::vertex_t> & createdVertices, std::vector<htd::vertex_t> & removedVertices) const HTD_OVERRIDE;

            void apply(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const HTD_OVERRIDE;

            void apply(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::vertex_t> & relevantVertices, const std::vector<htd::ILabelingFunction *> & labelingFunctions, std::vector<htd::vertex_t> & createdVertices, std::vector<htd::vertex_t> & removedVertices) const HTD_OVERRIDE;

            bool isLocalOperation(void) const HTD_OVERRIDE;

            bool createsTreeNodes(void) const HTD_OVERRIDE;

            bool removesTreeNodes(void) const HTD_OVERRIDE;

            bool modifiesBagContents(void) const HTD_OVERRIDE;

            bool createsSubsetMaximalBags(void) const HTD_OVERRIDE;

            bool createsLocationDependendLabels(void) const HTD_OVERRIDE;

            /**
             *  Set the manipulations which are applied globally to each decomposition generated by the algorithm. The manipulation operations are applied in the given order.
             *
             *  @note When calling this method the control over the memory regions of the manipulation operations is transferred to the
             *  optimization operation. Deleting a manipulation operation provided to this method outside the optimization operation or
             *  assigning the same manipulation operation multiple times will lead to undefined behavior.
             *
             *  @param[in] manipulationOperations   The manipulation operations which shall be applied globally to each decomposition generated by the algorithm.
             */
            void setManipulationOperations(const std::vector<htd::ITreeDecompositionManipulationOperation *> & manipulationOperations);

            /**
             *  Add a new manipulation operation which shall be applied globally to each decomposition generated by the algorithm. The manipulation operations are applied in the given order.
             *
             *  @note When calling this method the control over the memory region of the manipulation operation is transferred to the optimization
             *  operation. Deleting the manipulation operation provided to this method outside the optimization operation or assigning the same
             *  manipulation operation multiple times will lead to undefined behavior.
             *
             *  @param[in] manipulationOperation    The manipulation operation which shall be applied globally to each decomposition generated by the algorithm.
             */
            void addManipulationOperation(htd::ITreeDecompositionManipulationOperation * manipulationOperation);

            /**
             *  Add additional manipulation operations which shall be applied globally to each decomposition generated by the algorithm. The manipulation operations are applied in the given order.
             *
             *  @note When calling this method the control over the memory regions of the manipulation operations is transferred to the
             *  optimization operation. Deleting a manipulation operation provided to this method outside the optimization operation or
             *  assigning the same manipulation operation multiple times will lead to undefined behavior.
             *
             *  @param[in] manipulationOperations   The manipulation operations which shall be applied globally to each decomposition generated by the algorithm.
             */
            void addManipulationOperations(const std::vector<htd::ITreeDecompositionManipulationOperation *> & manipulationOperations);

            /**
             *  Set the strategy defining which vertices shall be considered as root of the tree decomposition.
             *
             *  @note When calling this method the control over the memory regions of the vertex selection strategy is transferred to the
             *  optimization operation. Deleting the vertex selection strategy provided to this method outside the optimization operation
             *  or assigning the same the vertex selection strategy multiple times will lead to undefined behavior.
             *
             *  @param[in] strategy The new vertex selection strategy which shall be used.
             */
            void setVertexSelectionStrategy(htd::IVertexSelectionStrategy * strategy);

            TreeDecompositionOptimizationOperation * clone(void) const HTD_OVERRIDE;

        private:
            bool enforceNaiveOptimization_;

            htd::IVertexSelectionStrategy * strategy_;

            htd::ITreeDecompositionFitnessFunction * fitnessFunction_;

            std::vector<htd::ITreeDecompositionManipulationOperation *> manipulationOperations_;

            bool isSafeOperation(const htd::ITreeDecompositionManipulationOperation & manipulationOperation) const;

            void quickOptimization(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition) const;

            void naiveOptimization(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const;

            void intelligentOptimization(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const;

            void removeCreatedNodes(htd::IMutableTreeDecomposition & decomposition, htd::vertex_t start, htd::vertex_t lastRegularVertex) const;
    };
}

#endif /* HTD_HTD_TREEDECOMPOSITIONOPTIMIZATIONOPERATION_HPP */
