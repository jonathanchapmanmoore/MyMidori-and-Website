using System.CodeDom;
using System.Collections.Specialized;
using System.Extensions.CodeDom.Collections;

namespace System.Extensions.CodeDom
{
    public interface IClassDeclaration
    {
        StringConstantDeclaration Constans { get; }
        EventDeclarationCollection Events { get; }
        StringFieldDeclarationDictionary Fields { get; }
        string FullName { get; }
        IndexerDeclarationCollection Indexers { get; }
        string InterfaceName { get; }
        TypeDeclarationCollection Interfaces { get; }
        MethodDeclarationCollection Methods { get; }
        NamespaceDeclaration Namespace { get; }
        StringClassDeclarationDictionary NestedClasses { get; }
        ClassOutputType OutputType { get; set; }
        ITypeDeclaration Parent { get; set; }
        PropertyDeclarationCollection Properties { get; }

        ClassDeclaration AddClass(string name);
        ConstantDeclaration AddConstant(Type type, string name, SnippetExpression expression);
        ConstructorDeclaration AddConstructor();
        EventDeclaration AddEvent(ITypeDeclaration type, string name);
        EventDeclaration AddEvent(string type, string name);
        EventDeclaration AddEvent(Type type, string name);
        FieldDeclaration AddField(ITypeDeclaration type, string name);
        FieldDeclaration AddField(string type, string name);
        FieldDeclaration AddField(Type type, string name);
        IndexerDeclaration AddIndexer(ITypeDeclaration type);
        IndexerDeclaration AddIndexer(string type);
        IndexerDeclaration AddIndexer(Type type);
        MethodDeclaration AddMethod(string name);
        PropertyDeclaration AddProperty(FieldDeclaration f, bool hasGet, bool hasSet, bool checkNonNull);
        PropertyDeclaration AddProperty(ITypeDeclaration type, string name);
        PropertyDeclaration AddProperty(string type, string name);
        PropertyDeclaration AddProperty(Type type, string name);
        StringCollection GetImports();
        void ToCodeDom(CodeTypeDeclarationCollection types);
    }
}