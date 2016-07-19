/*
 * File:   LimitChildCountOperation.cpp
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

#ifndef HTD_HTD_LIMITCHILDCOUNTOPERATION_CPP
#define	HTD_HTD_LIMITCHILDCOUNTOPERATION_CPP

#include <htd/Globals.hpp>
#include <htd/Helpers.hpp>
#include <htd/LimitChildCountOperation.hpp>

#include <algorithm>
#include <stdexcept>
#include <iterator>

htd::LimitChildCountOperation::LimitChildCountOperation(std::size_t limit) : htd::LibraryObject(), limit_(limit)
{
    HTD_ASSERT(limit > 0)
}

htd::LimitChildCountOperation::~LimitChildCountOperation()
{

}

void htd::LimitChildCountOperation::apply(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition) const
{
    apply(graph, decomposition, std::vector<htd::ILabelingFunction *>());
}

void htd::LimitChildCountOperation::apply(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::vertex_t> & relevantVertices, std::vector<htd::vertex_t> & createdVertices, std::vector<htd::vertex_t> & removedVertices) const
{
    apply(graph, decomposition, relevantVertices, std::vector<htd::ILabelingFunction *>(), createdVertices, removedVertices);
}

void htd::LimitChildCountOperation::apply(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const
{
    HTD_UNUSED(graph)

    std::vector<htd::vertex_t> joinNodes;

    decomposition.copyJoinNodesTo(joinNodes);

    for (auto it = joinNodes.begin(); it != joinNodes.end() && !isTerminated(); ++it)
    {
        htd::vertex_t node = *it;

        std::size_t childCount = decomposition.childCount(node);

        if (childCount > limit_)
        {
            const std::vector<htd::vertex_t> & bag = decomposition.bagContent(node);

            const htd::FilteredHyperedgeCollection & inducedHyperedges = decomposition.inducedHyperedges(node);

            std::vector<htd::vertex_t> children;

            decomposition.copyChildrenTo(children, node);

            htd::index_t index = limit_ - 1;

            htd::vertex_t attachmentPoint = node;

            while (childCount - index > limit_)
            {
                htd::vertex_t newNode = decomposition.addChild(attachmentPoint);

                decomposition.bagContent(newNode) = bag;

                decomposition.inducedHyperedges(newNode) = inducedHyperedges;

                for (auto & labelingFunction : labelingFunctions)
                {
                    htd::ILabelCollection * labelCollection = decomposition.labelings().exportVertexLabelCollection(newNode);

                    htd::ILabel * newLabel = labelingFunction->computeLabel(decomposition.bagContent(newNode), *labelCollection);

                    delete labelCollection;

                    decomposition.setVertexLabel(labelingFunction->name(), newNode, newLabel);
                }

                attachmentPoint = newNode;

                for (htd::index_t childPosition = index; childPosition < index + limit_ - 1; ++childPosition)
                {
                    decomposition.setParent(children[childPosition], attachmentPoint);
                }

                index += limit_ - 1;
            }

            if (index < childCount)
            {
                htd::vertex_t newNode = decomposition.addChild(attachmentPoint);

                decomposition.bagContent(newNode) = bag;

                decomposition.inducedHyperedges(newNode) = inducedHyperedges;

                for (auto & labelingFunction : labelingFunctions)
                {
                    htd::ILabelCollection * labelCollection = decomposition.labelings().exportVertexLabelCollection(newNode);

                    htd::ILabel * newLabel = labelingFunction->computeLabel(decomposition.bagContent(newNode), *labelCollection);

                    delete labelCollection;

                    decomposition.setVertexLabel(labelingFunction->name(), newNode, newLabel);
                }

                attachmentPoint = newNode;

                for (htd::index_t childPosition = index; childPosition < childCount; ++childPosition)
                {
                    decomposition.setParent(children[childPosition], attachmentPoint);
                }
            }
        }
    }
}

void htd::LimitChildCountOperation::apply(const htd::IMultiHypergraph & graph, htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::vertex_t> & relevantVertices, const std::vector<htd::ILabelingFunction *> & labelingFunctions, std::vector<htd::vertex_t> & createdVertices, std::vector<htd::vertex_t> & removedVertices) const
{
    HTD_UNUSED(graph)
    HTD_UNUSED(removedVertices)

    for (auto it = relevantVertices.begin(); it != relevantVertices.end() && !isTerminated(); ++it)
    {
        htd::vertex_t vertex = *it;

        std::size_t childCount = decomposition.childCount(vertex);

        if (childCount > limit_)
        {
            const std::vector<htd::vertex_t> & bag = decomposition.bagContent(vertex);

            const htd::FilteredHyperedgeCollection & inducedHyperedges = decomposition.inducedHyperedges(vertex);

            std::vector<htd::vertex_t> children;

            decomposition.copyChildrenTo(children, vertex);

            htd::index_t index = limit_ - 1;

            htd::vertex_t attachmentPoint = vertex;

            while (childCount - index > limit_)
            {
                htd::vertex_t newNode = decomposition.addChild(attachmentPoint);

                decomposition.bagContent(newNode) = bag;

                decomposition.inducedHyperedges(newNode) = inducedHyperedges;

                for (auto & labelingFunction : labelingFunctions)
                {
                    htd::ILabelCollection * labelCollection = decomposition.labelings().exportVertexLabelCollection(newNode);

                    htd::ILabel * newLabel = labelingFunction->computeLabel(decomposition.bagContent(newNode), *labelCollection);

                    delete labelCollection;

                    decomposition.setVertexLabel(labelingFunction->name(), newNode, newLabel);
                }

                attachmentPoint = newNode;

                for (htd::index_t childPosition = index; childPosition < index + limit_ - 1; ++childPosition)
                {
                    decomposition.setParent(children[childPosition], attachmentPoint);
                }

                createdVertices.push_back(newNode);

                index += limit_ - 1;
            }

            if (index < childCount)
            {
                htd::vertex_t newNode = decomposition.addChild(attachmentPoint);

                decomposition.bagContent(newNode) = bag;

                decomposition.inducedHyperedges(newNode) = inducedHyperedges;

                for (auto & labelingFunction : labelingFunctions)
                {
                    htd::ILabelCollection * labelCollection = decomposition.labelings().exportVertexLabelCollection(newNode);

                    htd::ILabel * newLabel = labelingFunction->computeLabel(decomposition.bagContent(newNode), *labelCollection);

                    delete labelCollection;

                    decomposition.setVertexLabel(labelingFunction->name(), newNode, newLabel);
                }

                attachmentPoint = newNode;

                for (htd::index_t childPosition = index; childPosition < childCount; ++childPosition)
                {
                    decomposition.setParent(children[childPosition], attachmentPoint);
                }

                createdVertices.push_back(newNode);
            }
        }
    }
}

bool htd::LimitChildCountOperation::isLocalOperation(void) const
{
    return true;
}

bool htd::LimitChildCountOperation::createsTreeNodes(void) const
{
    return true;
}

bool htd::LimitChildCountOperation::removesTreeNodes(void) const
{
    return false;
}

bool htd::LimitChildCountOperation::modifiesBagContents(void) const
{
    return false;
}

bool htd::LimitChildCountOperation::createsSubsetMaximalBags(void) const
{
    return false;
}

bool htd::LimitChildCountOperation::createsLocationDependendLabels(void) const
{
    return false;
}

htd::LimitChildCountOperation * htd::LimitChildCountOperation::clone(void) const
{
    htd::LimitChildCountOperation * ret = new htd::LimitChildCountOperation(limit_);

    ret->setManagementInstance(managementInstance());

    return ret;
}

#endif /* HTD_HTD_LIMITCHILDCOUNTOPERATION_CPP */
