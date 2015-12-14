/* 
 * File:   IPathDecomposition.hpp
 *
 * Author: ABSEHER Michael (abseher@dbai.tuwien.ac.at)
 * 
 * Copyright 2015, Michael Abseher
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

#ifndef HTD_HTD_IPATHDECOMPOSITION_HPP
#define	HTD_HTD_IPATHDECOMPOSITION_HPP

#include <htd/Globals.hpp>
#include <htd/ILabeledPath.hpp>

namespace htd
{
    class IPathDecomposition : public virtual htd::ILabeledPath
    {
        public:
            virtual ~IPathDecomposition() = 0;

            virtual std::size_t forgetNodeCount(void) const = 0;

            virtual const htd::Collection<htd::vertex_t> forgetNodes(void) const = 0;

            virtual htd::vertex_t forgetNode(htd::index_t index) const = 0;

            virtual bool isForgetNode(htd::vertex_t vertex) const = 0;

            virtual std::size_t introduceNodeCount(void) const = 0;

            virtual const htd::Collection<htd::vertex_t> introduceNodes(void) const = 0;

            virtual htd::vertex_t introduceNode(htd::index_t index) const = 0;

            virtual bool isIntroduceNode(htd::vertex_t vertex) const = 0;

            virtual const htd::Collection<htd::vertex_t> bagContent(htd::vertex_t vertex) const = 0;

            virtual std::size_t forgottenVerticesCount(htd::vertex_t vertex) const = 0;

            virtual std::size_t forgottenVerticesCount(htd::vertex_t vertex, htd::vertex_t child) const = 0;

            virtual void getForgottenVertices(htd::vertex_t vertex, htd::vertex_container & output) const = 0;

            virtual void getForgottenVertices(htd::vertex_t vertex, htd::vertex_container & output, htd::vertex_t child) const = 0;

            virtual htd::vertex_t forgottenVertex(htd::vertex_t vertex, htd::index_t index) const = 0;

            virtual htd::vertex_t forgottenVertex(htd::vertex_t vertex, htd::index_t index, htd::vertex_t child) const = 0;

            virtual bool isForgottenVertex(htd::vertex_t vertex, htd::vertex_t forgottenVertex) const = 0;

            virtual bool isForgottenVertex(htd::vertex_t vertex, htd::vertex_t forgottenVertex, htd::vertex_t child) const = 0;

            virtual std::size_t introducedVerticesCount(htd::vertex_t vertex) const = 0;

            virtual std::size_t introducedVerticesCount(htd::vertex_t vertex, htd::vertex_t child) const = 0;

            virtual void getIntroducedVertices(htd::vertex_t vertex, htd::vertex_container & output) const = 0;

            virtual void getIntroducedVertices(htd::vertex_t vertex, htd::vertex_container & output, htd::vertex_t child) const = 0;

            virtual htd::vertex_t introducedVertex(htd::vertex_t vertex, htd::index_t index) const = 0;

            virtual htd::vertex_t introducedVertex(htd::vertex_t vertex, htd::index_t index, htd::vertex_t child) const = 0;

            virtual bool isIntroducedVertex(htd::vertex_t vertex, htd::vertex_t introducedVertex) const = 0;

            virtual bool isIntroducedVertex(htd::vertex_t vertex, htd::vertex_t introducedVertex, htd::vertex_t child) const = 0;

            virtual std::size_t rememberedVerticesCount(htd::vertex_t vertex) const = 0;

            virtual std::size_t rememberedVerticesCount(htd::vertex_t vertex, htd::vertex_t child) const = 0;

            virtual void getRememberedVertices(htd::vertex_t vertex, htd::vertex_container & output) const = 0;

            virtual void getRememberedVertices(htd::vertex_t vertex, htd::vertex_container & output, htd::vertex_t child) const = 0;

            virtual htd::vertex_t rememberedVertex(htd::vertex_t vertex, htd::index_t index) const = 0;

            virtual htd::vertex_t rememberedVertex(htd::vertex_t vertex, htd::index_t index, htd::vertex_t child) const = 0;

            virtual bool isRememberedVertex(htd::vertex_t vertex, htd::vertex_t rememberedVertex) const = 0;

            virtual bool isRememberedVertex(htd::vertex_t vertex, htd::vertex_t rememberedVertex, htd::vertex_t child) const = 0;

            virtual std::size_t minimumBagSize(void) const = 0;

            virtual std::size_t maximumBagSize(void) const = 0;

            virtual IPathDecomposition * clone(void) const = 0;
    };

    inline htd::IPathDecomposition::~IPathDecomposition() { }
}

#endif /* HTD_HTD_IPATHDECOMPOSITION_HPP */
