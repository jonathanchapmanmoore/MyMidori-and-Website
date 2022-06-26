// This file is used by Code Analysis to maintain SuppressMessage 
// attributes that are applied to this project.
// Project-level suppressions either have no target or are given 
// a specific target and scoped to a namespace, type, member, etc.
//
// To add a suppression to this file, right-click the message in the 
// Error List, point to "Suppress Message(s)", and click 
// "In Project Suppression File".
// You do not need to add suppressions to this file manually.


[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA2210:AssembliesShouldHaveValidStrongNames")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.Interop.NativeColorRef.#set_Dword(System.UInt32)")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1031:DoNotCatchGeneralExceptionTypes", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.PreviewHandler.#Microsoft.Windows.ShellExtensions.Interop.IPreviewHandler.DoPreview()")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Security", "CA2122:DoNotIndirectlyExposeMethodsWithLinkDemands", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.WpfPreviewHandler.#Initialize()")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1805:DoNotInitializeUnnecessarily", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.ThumbnailProvider.#.ctor()")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1805:DoNotInitializeUnnecessarily", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.WpfPreviewHandler.#.ctor()")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1709:IdentifiersShouldBeCasedCorrectly", MessageId = "API")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1709:IdentifiersShouldBeCasedCorrectly", Scope = "namespace", Target = "Microsoft.Windows.ShellExtensions.Interop", MessageId = "API")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1709:IdentifiersShouldBeCasedCorrectly", Scope = "namespace", Target = "Microsoft.Windows.ShellExtensions", MessageId = "API")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1704:IdentifiersShouldBeSpelledCorrectly", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.PreviewHandler.#SetBackground(System.Int32)", MessageId = "argb")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1704:IdentifiersShouldBeSpelledCorrectly", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.PreviewHandler.#SetForeground(System.Int32)", MessageId = "argb")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1711:IdentifiersShouldNotHaveIncorrectSuffix", Scope = "type", Target = "Microsoft.Windows.ShellExtensions.IThumbnailFromStream")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1711:IdentifiersShouldNotHaveIncorrectSuffix", Scope = "type", Target = "Microsoft.Windows.ShellExtensions.IPreviewFromStream")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.ThumbnailProvider.#System.Runtime.InteropServices.ICustomQueryInterface.GetInterface(System.Guid&,System.IntPtr&)")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.PreviewHandler.#System.Runtime.InteropServices.ICustomQueryInterface.GetInterface(System.Guid&,System.IntPtr&)")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1014:MarkAssembliesWithClsCompliant")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1024:UsePropertiesWhereAppropriate", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.ThumbnailProvider.#GetThumbnailAlphaType()")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA2210:AssembliesShouldHaveValidStrongNames")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1709:IdentifiersShouldBeCasedCorrectly", MessageId = "API")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1709:IdentifiersShouldBeCasedCorrectly", MessageId = "API", Scope = "namespace", Target = "Microsoft.Windows.ShellExtensions")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1709:IdentifiersShouldBeCasedCorrectly", MessageId = "API", Scope = "namespace", Target = "Microsoft.Windows.ShellExtensions.Interop")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1711:IdentifiersShouldNotHaveIncorrectSuffix", Scope = "type", Target = "Microsoft.Windows.ShellExtensions.IPreviewFromStream")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1711:IdentifiersShouldNotHaveIncorrectSuffix", Scope = "type", Target = "Microsoft.Windows.ShellExtensions.IThumbnailFromStream")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1031:DoNotCatchGeneralExceptionTypes", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.PreviewHandlers.PreviewHandler.#Microsoft.Windows.ShellExtensions.Interop.IPreviewHandler.DoPreview()", Justification = "Exception is handled later")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1031:DoNotCatchGeneralExceptionTypes", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.PreviewHandler.#Microsoft.Windows.ShellExtensions.Interop.IPreviewHandler.DoPreview()", Justification = "Exception is handled later")]

// All link demand related warnings suppressed.
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Security", "CA2122:DoNotIndirectlyExposeMethodsWithLinkDemands", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.ThumbnailProvider.#Microsoft.Windows.ShellExtensions.Interop.IThumbnailProvider.GetThumbnail(System.UInt32,System.IntPtr&,System.UInt32&)")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Security", "CA2122:DoNotIndirectlyExposeMethodsWithLinkDemands", Scope = "member", Target = "Microsoft.Windows.ShellExtensions.WpfPreviewHandler.#Initialize()")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes", Scope = "member", Justification = "Interfaces are implemented explicitly because they are native COM interfaces, we do not want child types to call them.", Target = "Microsoft.Windows.ShellExtensions.ThumbnailProvider.#System.Runtime.InteropServices.ICustomQueryInterface.GetInterface(System.Guid&,System.IntPtr&)")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes", Scope = "member", Justification = "Interfaces are implemented explicitly because they are native COM interfaces, we do not want child types to call them.", Target = "Microsoft.Windows.ShellExtensions.PreviewHandler.#System.Runtime.InteropServices.ICustomQueryInterface.GetInterface(System.Guid&,System.IntPtr&)")]

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1014:MarkAssembliesWithClsCompliant", Justification = "There are places where unsigned values are used, which is considered not Cls compliant.")]
[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode", Scope = "member", Justification = "Populated via marshaling.", Target = "Microsoft.Windows.ShellExtensions.Interop.NativeColorRef.#Dword")]
