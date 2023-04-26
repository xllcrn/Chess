//
// Created by xllcr on 06/04/2023.
//

//#pragma once
//#include "PieceFactory.h"
//#include "BoardFactory.h"
//#include "Position.h"
//#include "Piece.h"
//#include <cassert>
//
//class ChessBoardBuilderBase
//{
//public:
//    virtual ~ChessBoardBuilderBase(){};
//    virtual void  fillBoard(std::string const &) =0;
//};
//
//class ChessBoardBuilder : public ChessBoardBuilderBase{
//private:
//    using value = std::shared_ptr<Piece>;
//    using brdPtr = Board*;
//    brdPtr m_chessboard=nullptr;
////    BuildBoardFactory m_boardFactory;
//    BuildPieceFactory m_pieceFactory;
//public:
//    ChessBoardBuilder(){this->reset();}
//    void reset(){
////        auto p_board = m_boardFactory.make_board(typeBoard);
//      if (m_chessboard!=nullptr) delete m_chessboard;
//      std::cout << "je passe par un builder : reset";
//      m_chessboard = new Board();
////    this->m_chessboard=p_board;
//    };
//    void fillBoard(std::string const & board_str) {
//        auto rank=1;
//        auto i=-1;
//        std::string abc{"abcdefgh"};
//        auto hasMoved = true;
//        //auto p_board = m_boardFactory.make_board("map");
//
//        for (auto const & C : board_str){
//            ++i;
//            if(std::isdigit(C)) continue;
//            if (C=='/') {
//                i = -1;
//                ++rank;
//            }
//            else{
//                if (rank>8) assert("Bad string initialization to set boardchess pieces. Too much characters");
//                Color color=Color::WHITE;
//                if (isupper(C)) color=Color::BLACK;
//                Position pos=Position::create(abc[i],rank);
////            std::shared_ptr<Piece> p_piece = createPiece(C, pos, color);
//                auto p_piece = m_pieceFactory.make_piece(C);
//                if (p_piece!=nullptr) {
//                    if (p_piece->isInitialPosition(pos)) hasMoved = false;
//                    this->m_chessboard->insertPiece(pos,p_piece);
//                    this->m_chessboard->setkingPosition(pos, color);
//                }
//            }
//        }
//    }
////    void produceChessBoardColor(Color) const override;
//    brdPtr getProduct(){
//        brdPtr result = this-> m_chessboard;
//        this->reset();
//        return result;
//    }
//    static brdPtr create(std::string const & board_str){
//        // instantiate a builder
//        std::unique_ptr<ChessBoardBuilder<Range>> builder = std::make_unique<ChessBoardBuilder<Range>>();
//        builder->fillBoard(board_str);
//        return builder->getProduct();
//    }
//
//};
//

/**
 * The Director can construct several product variations using the same
 * building steps.
 */
//class Director{
//private:
//    std::shared_ptr<ChessBoardBuilderBase> builder;
//public:
//    void set_builder(std::shared_ptr<ChessBoardBuilderBase> );
//    Board* buildBoard(std::string const & );
//    Board* buildClassicChessBoard(std::string const & );
//    Board* buildFairyChessBoard(std::string const & );
//};
//
//// function !!!
//void ClientCode(Director& );

