////
//// Created by xllcr on 06/04/2023.
////
//
//#include "ChessBoardBuilder.h"
//#include <cassert>
//
//void ChessBoardBuilder::produceBoard(std::string const & board_str) {
////
//    auto rank=1;
//    auto i=-1;
//    std::string abc{"abcdefgh"};
//    auto hasMoved = true;
//    //auto p_board = m_boardFactory.make_board("map");
//
//    for (auto const & C : board_str){
//        ++i;
//        if(std::isdigit(C)) continue;
//        if (C=='/') {
//            i = -1;
//            ++rank;
//        }
//        else{
//            if (rank>8) assert("Bad string initialization to set boardchess pieces. Too much characters");
//            Color color=Color::WHITE;
//            if (isupper(C)) color=Color::BLACK;
//            Position pos=Position::create(abc[i],rank);
////            std::shared_ptr<Piece> p_piece = createPiece(C, pos, color);
//            auto p_piece = m_pieceFactory.make_piece(C);
//            if (p_piece!=nullptr) {
//                if (p_piece->isInitialPosition(pos)) hasMoved = false;
//                this->m_chessboard->insertPiece(pos,p_piece);
//                if (C == 'k') this->m_chessboard->m_kingW = pos;
//                if (C == 'K') this->m_chessboard->m_kingB = pos;
//            }
//        }
//    }
//}
//
//
//void ChessBoardBuilder::reset(std::string const & typeBoard){
//    auto p_board = m_boardFactory.make_board(typeBoard);
//    this->m_chessboard=p_board;
//};
//
//
//Board* ChessBoardBuilder::getProduct(std::string const & typeBoard){
//    Board* result = this-> m_chessboard;
//    this->reset(typeBoard);
//    return result;
//}
//
////void Director::set_builder(std::shared_ptr<ChessBoardBuilderBase> builder){
////    this->builder = builder;
////}
//
////void Director::buildBoard(){
////    this->builder->produceChessBoardBoard("rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR");
////    this->builder->produceChessBoardColor(Color::WHITE);
////}
//
////void Director::buildMinimalChessBoard(){
////    this->builder->produceChessBoardBoard("rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR");
////    this->builder->produceChessBoardColor(Color::WHITE);
////}
////
////void Director::buildCustomChessBoard(std::string const & board_str){
////    this->builder->produceChessBoardBoard(board_str);
////    this->builder->produceChessBoardColor(Color::WHITE);
////}
//
//
//
//Board* ChessBoardBuilder::create(std::string const & board_str)
//{
//    // instantiate a director
////    std::unique_ptr<Director> director= std::make_unique<Director>();
//    // instantiate a builder
//    std::shared_ptr<ChessBoardBuilder> builder = std::make_shared<ChessBoardBuilder>(ChessBoardBuilder(typeBoard));
//
//    builder->produceBoard(board_str);
////    builder->produceChessBoardColor(Color::WHITE);
//
//    return builder->getProduct(typeBoard);
//}
//
//ChessBoardBuilder::ChessBoardBuilder( std::string const & typeBoard){
//    this->reset(typeBoard);
//}