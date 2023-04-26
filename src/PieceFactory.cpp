#include "PieceFactory.h"



std::shared_ptr<Piece> PawnFactory::make(Color color) const {
    return std::make_shared<Pawn>(Pawn(color));
}


std::shared_ptr<Piece> QueenFactory::make(Color color) const {
    return std::make_shared<Queen>(Queen(color));
}

std::shared_ptr<Piece> RookFactory::make(Color color) const {
    return std::make_shared<Rook>(Rook(color));
}

std::shared_ptr<Piece> KnightFactory::make(Color color) const {
    return std::make_shared<Knight>(Knight(color));
}

std::shared_ptr<Piece> KingFactory::make(Color color) const {
    return std::make_shared<King>(King(color));
}

std::shared_ptr<Piece> CrossFactory::make(Color color) const {
    return std::make_shared<Cross>(Cross(color));
}

std::shared_ptr<Piece> BishopFactory::make(Color color) const {
    return std::make_shared<Bishop>(Bishop(color));
}


BuildPieceFactory::BuildPieceFactory(){
        piece_factories.emplace('p', std::make_shared<PawnFactory>());
        piece_factories.emplace('q', std::make_shared<QueenFactory>());
        piece_factories.emplace('r', std::make_shared<RookFactory>());
        piece_factories.emplace('b', std::make_shared<BishopFactory>());
        piece_factories.emplace('h', std::make_shared<KnightFactory>());
        piece_factories.emplace('x', std::make_shared<CrossFactory>());
        piece_factories.emplace('k', std::make_shared<KingFactory>());
}

std::shared_ptr<Piece> BuildPieceFactory::make_piece(char const & name){
    Color color;
    if (isupper(name))
        color=Color::BLACK;
    else
        color=Color::WHITE;
    auto piece = piece_factories[tolower(name)]->make(color);
    return piece;
}
